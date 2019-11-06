#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "ccpp_UberCasino.h"

#ifndef __GAME_H
#define __GAME_H

using namespace std;

//The game_instance class holds on the overhead needed to keep track of all
//users and table information in the game.
//
//No constructor nessesary, so no need to argument constraints
class game_instance
{
	public:
      	Dealer D_pub; //object used to publish dealer information
      	Game   G_pub; //object used to publish the game information
		std::vector<PlayerState> pstates; //holds the states of the player 
      	
		game_instance();
		UberCasino::card_t calc_card_value(int val);//calculates the cards suite and card value 
													//based on int val 1-52
		void set_shoe(int x); //sets the shoe type for determining how the game functions
		vector<hand> table_values(); //calculate hand values for all users
		void deal_cards(); //dealer cards to the table
		void deal_one_card(int playerIndex); //deal a single card
		bool move_valid(int playerIndex, player_action_t action);
		void count_cards(card_t card); //keep track of the table count
		hand dealer_hand_value(); //returns the dealers hand value
		void clean_table(); //remove cards from the table
		void boot_player(long uid); //kick player out of a game
   
		dds_io<Dealer,DealerSeq,DealerTypeSupport_var,DealerTypeSupport,DealerDataWriter_var,
             DealerDataWriter,DealerDataReader_var,DealerDataReader> *d_io;
             
		dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
             GameDataWriter,GameDataReader_var,GameDataReader> *g_io;
             
        dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
             PlayerDataWriter,PlayerDataReader_var,PlayerDataReader> *p_io;
              
		int shoe_type;
		int table_count;
		int shoe_iter; //iterator that tells where to deal the next card in the shoe
		int dcards_i; //tracks the number of cards in the dealers hand
		vector<card_t> shoe_v;//vector containing all cards in the shoe
		std::vector<player_instance> players;
};


void testshoe_1(game_instance *g);
void testshoe_2(game_instance *g);
void testshoe_3(game_instance *g);
void testshoe_4(game_instance *g);
void testshoe_5(game_instance *g);
void testshoe_6(game_instance *g);
void testshoe_7(game_instance *g);
void testshoe_8(game_instance *g);
void testshoe_9(game_instance *g);
void testshoe_10(game_instance *g);

#endif
