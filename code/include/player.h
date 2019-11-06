#include <string>
#include <iostream>
#include "ccpp_UberCasino.h"
#include "io.h"

#ifndef __PLAYER_H
#define __PLAYER_H

using namespace std;
using namespace UberCasino;

struct hand 
{
	vector <int> value;
}typedef hand;

//declaration for linking purposes
class game_instance;

//This class provides overhead that the idl version of Player did not provide.
//Constructor take in a Player object, defined in the IDL file, and converts it to
//something we can use in our program
class player_instance
{
	public:
		player_instance(Player P);
		string suggest_move(int dealer_card); //based off the cards on the table suggest what the player should do
		hand hand_value(); // returns
		void tick_clock(); //decrement clock by 1 every sec until zero
		void add_card(card_t card); //add the cards the dealer has delt to the players hand
		void clean_hand(); //empty cards from players hand at the end of the hand
		vector<card_t> cards; //holds players cards
		Player P; //holds the Player object received from oopen splice
		bool active;
		int num_cards; //number of cards in the players hand
		int player_num; //index of the player (i.e. 0 == Player 1)
		unsigned int clock; //holds the players time clock
		string name; //The players name to be displayed in the GUI
		
	private:
		friend game_instance;
};

#endif
