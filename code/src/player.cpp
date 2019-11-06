#include <unistd.h>
#include "player.h"
#include "time.h"

using namespace UberCasino;

static bool waiting_player_move;//flag for players 7 second clock

player_instance::player_instance(Player P) : active(true),num_cards(0), clock(7) 
{
	this->name = (string)P.name;
}

//based off the cards on the table suggest what the player should do
string player_instance::suggest_move(int dealer_card)
{
	vector<string> moves;
	moves.push_back("hit");
	moves.push_back("stand");
	moves.push_back("double down");
	moves.push_back("split");
	string result = "Player ";
	stringstream ss;
	ss << (this->player_num + 1);
	result = result + ss.str() + " should ";
	
	int lookup_table[26][10] = {	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
									{1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
									{1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
									{1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
									{1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
									{0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
									{2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
									{2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
									{0, 2, 2, 2, 2, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
									{1, 2, 2, 2, 2, 1, 1, 0, 0, 0},
									{0, 2, 2, 2, 2, 0, 0, 0, 0, 0},
									{0, 0, 2, 2, 2, 0, 0, 0, 0, 0},
									{0, 0, 2, 2, 2, 0, 0, 0, 0, 0},
									{0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
									{0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
									{3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
									{3, 3, 3, 3, 3, 1, 3, 3, 1, 1},
									{3, 3, 3, 3, 3, 3, 0, 0, 0, 0},
									{3, 3, 3, 3, 3, 0, 0, 0, 0, 0},
									{2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
									{0, 0, 0, 3, 3, 0, 0, 0, 0, 0},
									{3, 3, 3, 3, 3, 3, 0, 0, 0, 0},
									{3, 3, 3, 3, 3, 3, 0, 0, 0, 0}	};
														
	int dealer_index = dealer_card - 2, hand_index = -1, hand_val;
	hand hand_vec = hand_value();
	
	hand_val = hand_vec.value[0];
	
	if (this->cards.size() == 2)
	{
		if (this->cards[0].card == eight && this->cards[1].card == eight)
			hand_index = 17;
		else if (this->cards[0].card == ten && this->cards[1].card == ten)
			hand_index = 18;
		else if (this->cards[0].card == nine && this->cards[1].card == nine)
			hand_index = 19;
		else if (this->cards[0].card == seven && this->cards[1].card == seven)
			hand_index = 20;
		else if (this->cards[0].card == six && this->cards[1].card == six)
			hand_index = 21;
		else if (this->cards[0].card == five && this->cards[1].card == five)
			hand_index = 22;
		else if (this->cards[0].card == four && this->cards[1].card == four)
			hand_index = 23;
		else if (this->cards[0].card == three && this->cards[1].card == three)
			hand_index = 24;
		else if (this->cards[0].card == two && this->cards[1].card == two)
			hand_index = 25;
			
		if (this->cards[0].card == ace || this->cards[1].card == ace)
		{
			if (this->cards[0].card == ten || this->cards[1].card == ten)
				hand_index = 10;
			else if (this->cards[0].card == nine || this->cards[1].card == nine)
				hand_index = 10;
			else if (this->cards[0].card == eight || this->cards[1].card == eight)
				hand_index = 10;
			else if (this->cards[0].card == seven || this->cards[1].card == seven)
				hand_index = 11;
			else if (this->cards[0].card == six || this->cards[1].card == six)
				hand_index = 12;
			else if (this->cards[0].card == five || this->cards[1].card == five)
				hand_index = 13;
			else if (this->cards[0].card == four || this->cards[1].card == four)
				hand_index = 14;
			else if (this->cards[0].card == three || this->cards[1].card == three)
				hand_index = 15;
			else if (this->cards[0].card == two || this->cards[1].card == two)
				hand_index = 16;
			else if (this->cards[0].card == ace && this->cards[1].card == ace)
				hand_index = 17;
		}
	}
	
	if ( hand_index == -1 )
	{
		if (hand_val >= 17)
			hand_index = 0;
		else if (hand_val == 16)
			hand_index = 1;
		else if (hand_val == 15)
			hand_index = 2;
		else if (hand_val == 14)
			hand_index = 3;
		else if (hand_val == 13)
			hand_index = 4;
		else if (hand_val == 12)
			hand_index = 5;
		else if (hand_val == 11)
			hand_index = 6;
		else if (hand_val == 10)
			hand_index = 7;
		else if (hand_val == 9)
			hand_index = 8;
		else if (hand_val <= 8 && hand_val >= 5)
			hand_index = 9;
	}
	
	return result + moves[lookup_table[hand_index][dealer_index]];
}

//return the value of the players hand ex. 21
//Will calculate all possible hand values with aces
//First vector index will be least possible hand value, up to highest possible value
//handval.back() will hold the best hand value less than 22
hand player_instance::hand_value()
{
    int result = 0;
    int aces = 0;
    hand handval;
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        if (this->cards[i].card == ace) 
        {
            aces += 1;
            result += 1;
        }else if( this->cards[i].card == king || this->cards[i].card == queen || this->cards[i].card == jack )
        {
            result += 10;
        }else
        {
            result += ((int)this->cards[i].card + 1);//casts enum index to int + 1
        }
    }
    handval.value.push_back(result);//saves least hand val to index 0
    if (aces) 
    {//will save all possible values with aces less than 22 to hand, ascending order
        for (int i = 0; i<aces; i++) 
        {
            if ((result + 10) < 22)
                handval.value.push_back(result + 10);
            else   
            	break;
        }
    }
    return handval;
}

//decrement clock by 1 every sec until zero
void player_instance::tick_clock()
{
    clock = 7;//sets clock at 7 seconds
    while (clock != 0 && waiting_player_move == false)
	{
		sleep(1);
		clock--;
	}
}

//add the cards the dealer has delt to the players hand
void player_instance::add_card(card_t card)
{
    this->cards.push_back(card);
}

//empty cards from players hand at the end of the hand
void player_instance::clean_hand()
{
    for (unsigned int i = 0; i < this->cards.size(); i++) 
    {
        this->cards.pop_back();
    }
    this->cards.clear();
    return;
}

