#include <iostream>
#include <sstream> 
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <random>
#include <chrono>
#include "io.h"
#include "uuid.h"
#include "ccpp_UberCasino.h"

vector<card_t> dcards;
vector<card_t> mycards;
int balance;

using namespace std;
using namespace UberCasino;

int main (int argc, char* argv[])
{
	Player P;
		dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
             GameDataWriter,GameDataReader_var,GameDataReader> *g_io;
             g_io = new dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
                     GameDataWriter,GameDataReader_var,GameDataReader>
                ( (char*) "game", false, true );	dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
             PlayerDataWriter,PlayerDataReader_var,PlayerDataReader> *p_io;
     p_io = new dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
                     PlayerDataWriter,PlayerDataReader_var,PlayerDataReader>
                ( (char*) "player", true, false );
     // player unique ID
   	UID uuid = boost::uuids::random_generator()();
   	memcpy ( P.uid, &uuid, sizeof ( char ) * SIZE_OF_UUID );
   	while(!game_rec) { sleep(1);}
	memcpy ( P.game_uid, &received_game.game_uid, sizeof ( char ) * SIZE_OF_UUID );
	char name[50];
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	minstd_rand0 generator(seed);
	int r = generator();
	sprintf(name, "Player-%3.0d", r );
   	strncpy ( P.name,name,sizeof ( char ) * 12);
   	P.name[10] = '\0';
	p_io->publish(P);
	game_rec = false;
	int input;
	while(!game_rec && received_game.gstate != playing) { sleep(1);}
	cout << "Connected" << endl;
	while(1)
	{
		p_io->publish(P);
		cout << endl << "--------- " << name << " ---------" << endl;
		cout << "1 = Hit; 2 = Stand; 3 = Double; 0 = idle" << endl;
		cin >> input;
		if(input == 1)
			P.A = hitting;
		else if(input == 2)
			P.A = standing;
		else if(input == 3)
			P.A = doubling;
		else if(input == 0)
			P.A = idle;
	}
	
	
	return 0;
}
