#ifndef IO_H
#define IO_H
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <vector>
#include "time.h"
#include <pthread.h>

#include "DDSEntityManager.h"
#include "ccpp_UberCasino.h"

static UberCasino::Game received_game;
static bool game_rec = false;
extern bool waiting_f;
extern bool playing_f;
extern bool action_f;
extern vector<UberCasino::Player> *P_rec;
extern pthread_mutex_t mutex1;

using namespace DDS;
using namespace UberCasino;

// Interfaces to the pub/sub network
// this code is derived (copied!) from the opensplice examples
// Then copied & derived from Instructor!

// this is a terrible hack. was unable to use a polymorphic
// function signature through all of the generics and with
// a 'pointer to member' callback.
//
// thus, the reversion to the simplest static approach

//Receives and pulls information from OpenSplice for use in the game.
template <typename DATA_READER_VAR,typename SEQ,typename MSG> 
class read_listener: public virtual DDS::DataReaderListener
{
	public:
		read_listener() {}
		DATA_READER_VAR m_Reader;
		void player_received( Game p )
		{
			if( game_rec == false )
			{
				received_game = p;
				game_rec = true;
			}
			return;
		}
		void player_received( Dealer p ) {}
		void player_received ( Player P )
		{
			if( waiting_f == false )
				return;
			if( playing_f == false )	
			{
				if( P_rec->empty() )
				{
					P_rec->push_back( P );
				}
				else 
				{
					for( unsigned int i = 0;i< P_rec->size();i++ )
					{
						if( strncmp( (*P_rec)[i].uid, P.uid,SIZE_OF_UUID ) == 0 )
							return;
					}
					pthread_mutex_lock( &mutex1 );
					P_rec->push_back( P );
					pthread_mutex_unlock( &mutex1 );
				}
			}
			else
			{
				if( action_f == false )
				{
					action_f = true;
					P_rec->push_back( P );
				}
			}
			return;
		}
		
		/* Callback method implementation. */
		virtual void on_data_available(DDS::DataReader_ptr reader)
		{
			DDS::ReturnCode_t status;
			SEQ msgList;

			SampleInfoSeq infoSeq;
			status = m_Reader->take(msgList, infoSeq, LENGTH_UNLIMITED,
				ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
			checkStatus(status, "MsgDataReader::read");
			for (DDS::ULong i = 0; i < msgList.length(); i++)
			{
				if (msgList.length()>0) // you can get callback with no actual data payload
				{
					player_received( msgList[i] );
			
				}
			}
			status = m_Reader->return_loan(msgList, infoSeq);
			checkStatus(status, "MsgDataReader::return_loan");
		}

		virtual void on_requested_deadline_missed(DDS::DataReader_ptr reader,
			const DDS::RequestedDeadlineMissedStatus &status) {}

		virtual void on_requested_incompatible_qos(DDS::DataReader_ptr reader,
			const DDS::RequestedIncompatibleQosStatus &status) {}

		virtual void on_sample_rejected(DDS::DataReader_ptr reader, const DDS
			::SampleRejectedStatus &status){}

		virtual void on_liveliness_changed(DDS::DataReader_ptr reader, const DDS
			::LivelinessChangedStatus &status) {}

		virtual void on_subscription_matched(DDS::DataReader_ptr reader, const
			DDS::SubscriptionMatchedStatus &status) {}

		virtual void on_sample_lost(DDS::DataReader_ptr reader, const DDS
			::SampleLostStatus &status) {}

};

//OpenSplice IO object
template <typename MSG, typename SEQ, typename TYPE_SUPPORT_VAR, class TYPE_SUPPORT,
          typename DATA_WRITER_VAR, class DATA_WRITER, typename DATA_READER_VAR, class DATA_READER>
class dds_io
{
	typedef void (*cb_func_type)( MSG );
	private:
		DDSEntityManager mgr;
		TYPE_SUPPORT_VAR mt;
		DataWriter_var dwriter;
		DATA_WRITER_VAR listenerWriter;
		DataReader_var dreader;
		
   public:
		dds_io ( char *topicName, bool pub = false, bool sub = false ) 
		{
			DDSEntityManager mgr;

			// create domain participant
			char partition_name[] = "";
			mgr.createParticipant(partition_name);

			//create type
			mt = new TYPE_SUPPORT();
			mgr.registerType(mt.in());

			//create Topic
			mgr.createTopic( topicName );

			if (pub) // meaning we intend to publish from this object
			{
				//create Publisher
				mgr.createPublisher();

				// create DataWriter
				mgr.createWriter();

				// Publish Events
				dwriter = mgr.getWriter();
				listenerWriter = DATA_WRITER::_narrow(dwriter.in());
			}

			if (sub) // meaning we intend to subscribe
			{
				// this is a subscription
				//create Subscriber
				mgr.createSubscriber();

				// create DataReader
				mgr.createReader();

				DataReader_var dreader = mgr.getReader();
       
				read_listener<DATA_READER_VAR,SEQ,MSG> *myListener = new read_listener<DATA_READER_VAR,SEQ,MSG> ();

				myListener->m_Reader = DATA_READER::_narrow(dreader.in());
				checkHandle(myListener->m_Reader.in(), "MsgDataReader::_narrow");

				DDS::StatusMask mask = DDS::DATA_AVAILABLE_STATUS;
				myListener->m_Reader->set_listener(myListener, mask);
			}
		}

		void publish ( MSG D )
		{
			ReturnCode_t status = listenerWriter->write(D, DDS::HANDLE_NIL );
			checkStatus(status, "MsgDataWriter::write");
		}
};

#endif
