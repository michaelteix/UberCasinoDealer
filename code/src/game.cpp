#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "time.h"
#include "sys/time.h"

extern int test_shoe_type; //flag for what type of test shoe was selected

using namespace std;

//declaration of functions in gui.cpp
void undisplay_cards(int playerIndex, int cardIndex);
void display_cards(int playerIndex, int cardIndex, card_t card);

//generated unique user id from given function for game_id
//must pass in shoe type; 0 = Test, 1 = 8deck, 2 = Infinite
game_instance::game_instance() : table_count(0), shoe_iter(0), dcards_i(0)
{
    d_io = new dds_io<Dealer,DealerSeq,DealerTypeSupport_var,DealerTypeSupport,DealerDataWriter_var,
                     DealerDataWriter,DealerDataReader_var,DealerDataReader>
                ( (char*) "dealer", true, false );

   	g_io = new dds_io<Game,GameSeq,GameTypeSupport_var,GameTypeSupport,GameDataWriter_var,
                     GameDataWriter,GameDataReader_var,GameDataReader>
                ( (char*) "game", true, false );
                
    p_io = new dds_io<Player,PlayerSeq,PlayerTypeSupport_var,PlayerTypeSupport,PlayerDataWriter_var,
                     PlayerDataWriter,PlayerDataReader_var,PlayerDataReader>
                ( (char*) "player", false, true );
}


//set the shoe type
void game_instance::set_shoe(int x)
{
	this->shoe_type = x;
	if (shoe_type == 0) 
    {
        if (test_shoe_type == 1)
        {
            testshoe_1(this);
        }else if (test_shoe_type == 2)
        {
            testshoe_2(this);
        }else if (test_shoe_type == 3)
        {
            testshoe_3(this);
        }else if (test_shoe_type == 4)
        {
            testshoe_4(this);
        }else if (test_shoe_type == 5)
        {
            testshoe_5(this);
        }else if (test_shoe_type == 6)
        {
            testshoe_6(this);
        }else if (test_shoe_type == 7)
        {
            testshoe_7(this);
        }else if (test_shoe_type == 8)
        {
            testshoe_8(this);
        }else if (test_shoe_type == 9)
        {
            testshoe_9(this);
        }else if (test_shoe_type == 10)
        {
            testshoe_10(this);
        }
    }else if (shoe_type == 1)
    {
        //Fill shoe with 8 Decks
        shoe_v.reserve(416);
        for(int k = 0;k < 8;k++)
        {
            for(int i = 1;i<=52;i++)
            {
                UberCasino::card_t temp_card;
                //temp_card.set_face(true);//defaults cards to face up
                temp_card = calc_card_value(i);//calculates a card val & suite based on 1-52
                this->shoe_v.push_back(temp_card);
            }
        }
        random_shuffle(shoe_v.begin(),shoe_v.end() );
        //Randomly shuffle deck. See "random_shuffle" library
    }
}


// calculates hand values for all users
// will return a 2D vector of each players hand values
// use vector.back() to get the best hand value for that player
// all posible hand values will be in the vector from worst[0] to best[end]
// Dealer's hand value will be placed in index 0
vector<hand> game_instance::table_values()
{
    vector< hand > table_values;
    
    //Calculate hand for dealer, place in index 0
    int result = 0;
    int aces = 0;
    hand handval;
    for (int i = 0; i < (dcards_i+1); i++)
    {
        if (this->G_pub.dealer_cards[i].card == ace) {
            aces += 1;
            result += 1;
        }else if( this->G_pub.dealer_cards[i].card == king || this->G_pub.dealer_cards[i].card == queen || this->G_pub.dealer_cards[i].card == jack )
        {
            result += 10;
        }else
        {
            result += ((int)this->G_pub.dealer_cards[i].card + 1);//casts enum index to int + 1
        }
    }
    handval.value.push_back(result);//saves least hand val to index 0
    if (aces) {//will save all possible values with aces less than 22 to hand, ascending order
        for (int i = 0; i<aces; i++) {
            if ((result + 10) < 22) {
                handval.value.push_back(result + 10);
            }else   { break; }
        }
    }
    table_values.push_back( handval ); //Saves all possible hand values for dealer to row 0, best at end()
    
    //adds row with all player's possible hand values < 22 to 2D table values
    for (unsigned int i = 0; i < players.size(); i++) {
        table_values.push_back( players[i].hand_value() );
    }
    return table_values;
}

//calculates the cards suite and card value based on int val 1-52
//val 1-13 = clubs; 14-26 = diamonds; 27-39 = hearts; 40-52 = spades
UberCasino::card_t game_instance::calc_card_value(int val)
{
    UberCasino::card_t temp;
    if (val <= 13)
    {
        temp.suite = clubs;
        temp.card = (card_kind) (val - 1);
    }else if (val <= 26)
    {
        temp.suite = diamonds;
        temp.card = (card_kind) ( (val - 1) - 13 );
    }else if (val <= 39)
    {
        temp.suite = hearts;
        temp.card = (card_kind) ( (val - 1) - 26 );
    }else
    {
        temp.suite = hearts;
        temp.card = (card_kind) ( (val - 1) - 39 );
    }
    return temp;
}

//deal cards to the table
void game_instance::deal_cards()
{
    int N = (int)this->players.size();
    if(this->shoe_type == 1 || this->shoe_type == 0)//8-deck shoe and test shoes
    {
    	UberCasino::card_t dealtCard;
        for (int i = N - 1; i > -1; i--) 
        {
            if(this->players[i].active == false)
                continue;
            
            dealtCard = this->shoe_v[this->shoe_iter];
            dealtCard.valid = true;
            this->players[i].add_card(dealtCard);
            display_cards(i, 0, dealtCard);
            this->shoe_iter++;
            this->players[i].num_cards++;
            this->count_cards(dealtCard);
        }
        this->G_pub.dealer_cards[this->dcards_i] = this->shoe_v[this->shoe_iter];
        this->G_pub.dealer_cards[this->dcards_i].valid = false;
        display_cards(7, 0, this->G_pub.dealer_cards[this->dcards_i]);
        this->shoe_iter++;
        this->count_cards(this->G_pub.dealer_cards[this->dcards_i++]);
        
        for (int i = N - 1; i > -1; i--)
        {
            if(this->players[i].active == false)
                continue;
            
            card_t dealtCard = this->shoe_v[this->shoe_iter];
            dealtCard.valid = true;
            this->players[i].add_card(dealtCard);
            display_cards(i, 1, dealtCard);
            this->shoe_iter++;
            this->players[i].num_cards++;
            this->count_cards(dealtCard);
        }
        this->G_pub.dealer_cards[dcards_i] = this->shoe_v[this->shoe_iter];
        this->G_pub.dealer_cards[this->dcards_i].valid = true;
        display_cards( 7, 1, this->G_pub.dealer_cards[this->dcards_i]);
        this->shoe_iter++;
        this->count_cards(this->G_pub.dealer_cards[this->dcards_i++]);
    }else if(this->shoe_type == 2)//Infinite Shoe
    {
        UberCasino::card_t new_card;
        int value;
        for (int i = N; i >-1; i--) 
        {
            value = ( rand()%52 + 1); //generates random number between 1-52
            new_card = this->calc_card_value(value);//calculates card value based on 52 possible cards in a deck
            if (i != N) 
            {
                if(this->players[i].active == false)
                    continue;
            	
            	new_card.valid = true;
                this->players[i].add_card(new_card);
                display_cards(i, 0, new_card);
                this->count_cards(new_card);
                this->players[i].num_cards++;
            }else
            {
            	new_card.valid = false;
                this->G_pub.dealer_cards[this->dcards_i++] = (new_card);
                display_cards(i, 0, new_card);
                this->count_cards(new_card);
            }
        }
        
        for (int i = N; i >-1; i--) 
        {
            value = ( rand()%52 + 1); //generates random number between 1-52
            new_card = this->calc_card_value(value);//calculates card value based on 52 possible cards in a deck
            new_card.valid = true;
            if (i != N) 
            {
                if(this->players[i].active == false)
                    continue;
                
                this->players[i].add_card(new_card);
                display_cards(i, 1, new_card);
                this->count_cards(new_card);
                this->players[i].num_cards++;
            }else
            {
                this->G_pub.dealer_cards[this->dcards_i++] = (new_card);
                display_cards(i, 1, new_card);
                this->count_cards(new_card);
            }
        }
    }

}

void game_instance::deal_one_card(int playerIndex)
{
    if(this->shoe_type == 1 || this->shoe_type == 0)//8-deck shoe and test shoes
    {
    	UberCasino::card_t dealtCard;
    	if ( playerIndex == 7 )
    	{
    		this->G_pub.dealer_cards[this->dcards_i] = this->shoe_v[this->shoe_iter];
    		this->G_pub.dealer_cards[this->dcards_i].valid = true;
	        display_cards(7, this->dcards_i, this->G_pub.dealer_cards[this->dcards_i]);
	        this->shoe_iter++;
	        this->count_cards(this->G_pub.dealer_cards[this->dcards_i++]);
    	}
    	else
    	{
    		if(this->players[playerIndex].active == false)
                return;
            
            dealtCard = this->shoe_v[this->shoe_iter];
    		dealtCard.valid = true;
	        this->players[playerIndex].add_card(dealtCard);
	        display_cards(playerIndex, this->players[playerIndex].num_cards++, dealtCard);
	        this->shoe_iter++;
	        count_cards(dealtCard);
    	}
    }else if(this->shoe_type == 2 )//Infinite Shoe
    {
    	int value = ( rand()%52 + 1); //generates random number between 1-52
    	UberCasino::card_t new_card = calc_card_value(value);//calculates card value based on 52 possible cards in a deck
    	new_card.valid = true;
    	if ( playerIndex == 7 )
    	{
    		this->G_pub.dealer_cards[this->dcards_i] = (new_card);
            display_cards(playerIndex, ++this->dcards_i, new_card);
            count_cards(new_card);
    	}
    	else
    	{
    		if(this->players[playerIndex].active == false)
                return;
            
            this->players[playerIndex].add_card(new_card);
            display_cards(playerIndex, this->players[playerIndex].num_cards++, new_card);
            count_cards(new_card);
    	}
    }

}

hand game_instance::dealer_hand_value()
{
    int result = 0;
    int aces = 0;
    hand handval;
    for (int i = 0; i < this->dcards_i; i++)
    {
        if (this->G_pub.dealer_cards[i].card == ace) 
        {
            aces += 1;
            result += 1;
        }else if( this->G_pub.dealer_cards[i].card == king || this->G_pub.dealer_cards[i].card == queen 
        	|| this->G_pub.dealer_cards[i].card == jack )
        {
            result += 10;
        }else
        {
            result += ((int)this->G_pub.dealer_cards[i].card + 1);//casts enum index to int + 1
        }
    }
    handval.value.push_back(result);//saves least hand val to index 0
    if (aces)//will save all possible values with aces less than 22 to hand, ascending order
    {
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

//keep track of the running table count
// 2 - 6 = count +1, 10 - A = count - 1, else is 0
void game_instance::count_cards(card_t c)
{
    if ( c.card == two || c.card == three || c.card == four || c.card == five || c.card == six )
    {
        table_count += 1;
    }else if (c.card == ten || c.card == jack || c.card == queen || c.card == king ||  c.card == ace )
    {
        table_count -= 1;
    }
}


//check to see if a players move is valid
bool game_instance::move_valid(int playerIndex, player_action_t action)
{
	hand pHand = players[playerIndex].hand_value();
	
	if ( action == splitting )
		return false;
	
	if ( action == hitting || action == doubling )
	{
		if ( pHand.value[0] > 19 )
			return false;
	}
	
    return true;
}

void game_instance::clean_table()
{
	for (unsigned int i = 0; i < this->players.size(); i++)
	{
		if(this->players[i].active == false)
            continue;
        
        for (unsigned int j = this->players[i].cards.size() - 1; j > 0; j--)
		{
			undisplay_cards(i, j);
			this->players[i].cards.pop_back();
		}
		this->players[i].cards.clear();
		this->players[i].num_cards = 0;
	}
	for (int i = 0; i < this->dcards_i; i++)
	{
		card_t blankCard;
		undisplay_cards(7, i);
		this->G_pub.dealer_cards[i] = blankCard;
	}
	this->dcards_i = 0;
}

//kick player out of a game
void game_instance::boot_player(long index)
{
    this->players[ index ].active = false;
    this->players[ index ].clean_hand();
    return;
}


void testshoe_1(game_instance *g)
{
    //Fill shoe with 8 Decks of Dealer wins blackjack
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = i;
            if(j == 16)
                j = 0;
            UberCasino::card_t temp_card;
            if(j == 7)
                c = 1;
            if(j == 15)
                c = 10;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_2(game_instance *g)
{
    //Fill shoe with 8 Decks of Players wins blackjack, Dealer random
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = (rand() % 52) + 1;
            if(j == 16)
                j = 0;
            UberCasino::card_t temp_card;
            if(j >= 0 && j != 7)
                c = 1;
            if(j > 7 && j != 15)
                c = 10;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_3(game_instance *g)
{
     //Fill shoe with 8 Decks of Dealer gets between 4 & 20
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = (rand() % 52) + 1;
            if(j == 16)
                j = 0;
            UberCasino::card_t temp_card;
            if(j == 7 || j ==15)
                c = (rand() % 7) + 4;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_4(game_instance *g)
{
    //Fill shoe with 8 Decks of Players win with 19 & Dealer has 18
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = i;
            if(j == 16)
                j = 0;
            UberCasino::card_t temp_card;
            if(j >= 0)
                c = 10;
            if(j > 7)
                c = 9;

            if(j == 7)
                c = 10;
            if(j == 15)
                c = 8;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_5(game_instance *g)
{
    //Fill shoe with 8 Decks of Dealer wins with 20 and Players have 15
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = i;
            if(j == 16)
                j = 0;
            UberCasino::card_t temp_card;
            if(j >= 0 )
                c = 10;
            if(j > 7)
                c = 5;
            
            if(j == 7)
                c = 10;
            if(j == 15)
                c = 10;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_6(game_instance *g)
{
    //Fill shoe with 8 Decks of Players & Dealer wins blackjack
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = i;
            if(j == 16)
                j = 0;
            UberCasino::card_t temp_card;
            if(j >= 0)
                c = 1;
            if(j > 7)
                c = 10;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_7(game_instance *g)
{
    //Fill shoe with 8 Decks of Players get 19, hit, then bust
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = i;
            if(j == 23)
                j = 0;
            UberCasino::card_t temp_card;
            if(j >= 0 )
                c = 10;
            if(j > 7)
                c = 9;
            if(j > 15)
                c = 5;

            if(j == 7)
                c = 10;
            if(j == 15)
                c = 10;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_8(game_instance *g)
{
    //Fill shoe with 8 Decks of Players get a pair of twos
    g->shoe_v.reserve(416);
    int j = 0;
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            int c = i;
            if(j == 23)
                j = 0;
            UberCasino::card_t temp_card;
            if(j >= 0 )
                c = 2;
            if(j > 7)
                c = 2;
            if(j > 15)
                c = 10;
            
            if(j == 7)
                c = 10;
            if(j == 15)
                c = 10;
            temp_card = g->calc_card_value(c);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
            j++;
        }
    }
}
void testshoe_9(game_instance *g)
{
    //Fill shoe with 8 Decks of twos
    g->shoe_v.reserve(416);
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            UberCasino::card_t temp_card;
            temp_card = g->calc_card_value(2);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
        }
    }
}
void testshoe_10(game_instance *g)
{
    //Fill shoe with 8 Decks of twos
    g->shoe_v.reserve(416);
    for(int k = 0;k < 8;k++)
    {
        for(int i = 1;i<=52;i++)
        {
            UberCasino::card_t temp_card;
            temp_card = g->calc_card_value(2);//calculates a card val & suite based on 1-52
            g->shoe_v.push_back(temp_card);
        }
    }
}
