/*
	image file from http://acbl.mybigcommerce.com/52-playing-cards/
	
	These images can be used to enhance your marketing materials or website. Add them to fliers, handouts, newspaper ads and 		more to attract attendees to your event. For digital marketing materials (web) download the png version. For print marketing materials (fliers, handouts and newspaper ads) download the png version.
*/

#include <iostream>
#include <pthread.h>
#include <algorithm>
#include <cstring>
#include <string>
#include "sys/time.h"
#include "gui.h"
#include "enum_helpers.h"

vector<UberCasino::Player> *P_rec = new vector<UberCasino::Player>;
static unsigned int received_player_i;
bool start_botton_clicked;
bool player_rec = false;
bool game_over = false;
bool waiting_f = false;
bool playing_f = false;
bool action_f = false;
bool next_hand_f = false;
bool auto_deal = false;
pthread_mutex_t mutex1;
	
using namespace std;

Fl_Box *background=(Fl_Box *)0;
Fl_Button *Title=(Fl_Button *)0;
Fl_Group *Players=(Fl_Group *)0;
Fl_Group *Player_1=(Fl_Group *)0;
Fl_Output *P1_Status=(Fl_Output *)0;
Fl_Text_Display *P1_Name=(Fl_Text_Display *)0;
Fl_Text_Display *P1_ID=(Fl_Text_Display *)0;
Fl_Text_Display *P1_clock=(Fl_Text_Display *)0;
Fl_Box *P1C1=(Fl_Box *)0;
Fl_Box *P1C2=(Fl_Box *)0;
Fl_Box *P1C3=(Fl_Box *)0;
Fl_Box *P1C4=(Fl_Box *)0;
Fl_Box *P1C5=(Fl_Box *)0;
Fl_Box *P1C6=(Fl_Box *)0;
Fl_Box *P1C7=(Fl_Box *)0;
Fl_Text_Display *P1_hand_value=(Fl_Text_Display *)0;
Fl_Group *Player_2=(Fl_Group *)0;
Fl_Output *P2_Status=(Fl_Output *)0;
Fl_Text_Display *P2_Name=(Fl_Text_Display *)0;
Fl_Text_Display *P2_ID=(Fl_Text_Display *)0;
Fl_Text_Display *P2_clock=(Fl_Text_Display *)0;
Fl_Box *P2C1=(Fl_Box *)0;
Fl_Box *P2C2=(Fl_Box *)0;
Fl_Box *P2C3=(Fl_Box *)0;
Fl_Box *P2C4=(Fl_Box *)0;
Fl_Box *P2C5=(Fl_Box *)0;
Fl_Box *P2C6=(Fl_Box *)0;
Fl_Box *P2C7=(Fl_Box *)0;
Fl_Text_Display *P2_hand_value=(Fl_Text_Display *)0;
Fl_Group *Player_3=(Fl_Group *)0;
Fl_Output *P3_Status=(Fl_Output *)0;
Fl_Text_Display *P3_Name=(Fl_Text_Display *)0;
Fl_Text_Display *P3_ID=(Fl_Text_Display *)0;
Fl_Text_Display *P3_clock=(Fl_Text_Display *)0;
Fl_Box *P3C1=(Fl_Box *)0;
Fl_Box *P3C2=(Fl_Box *)0;
Fl_Box *P3C3=(Fl_Box *)0;
Fl_Box *P3C4=(Fl_Box *)0;
Fl_Box *P3C5=(Fl_Box *)0;
Fl_Box *P3C6=(Fl_Box *)0;
Fl_Box *P3C7=(Fl_Box *)0;
Fl_Text_Display *P3_hand_value=(Fl_Text_Display *)0;
Fl_Group *Player_4=(Fl_Group *)0;
Fl_Output *P4_Status=(Fl_Output *)0;
Fl_Text_Display *P4_Name=(Fl_Text_Display *)0;
Fl_Text_Display *P4_ID=(Fl_Text_Display *)0;
Fl_Text_Display *P4_clock=(Fl_Text_Display *)0;
Fl_Box *P4C1=(Fl_Box *)0;
Fl_Box *P4C2=(Fl_Box *)0;
Fl_Box *P4C3=(Fl_Box *)0;
Fl_Box *P4C4=(Fl_Box *)0;
Fl_Box *P4C5=(Fl_Box *)0;
Fl_Box *P4C6=(Fl_Box *)0;
Fl_Box *P4C7=(Fl_Box *)0;
Fl_Text_Display *P4_hand_value=(Fl_Text_Display *)0;
Fl_Group *Player_5=(Fl_Group *)0;
Fl_Output *P5_Status=(Fl_Output *)0;
Fl_Text_Display *P5_Name=(Fl_Text_Display *)0;
Fl_Text_Display *P5_ID=(Fl_Text_Display *)0;
Fl_Text_Display *P5_clock=(Fl_Text_Display *)0;
Fl_Box *P5C1=(Fl_Box *)0;
Fl_Box *P5C2=(Fl_Box *)0;
Fl_Box *P5C3=(Fl_Box *)0;
Fl_Box *P5C4=(Fl_Box *)0;
Fl_Box *P5C5=(Fl_Box *)0;
Fl_Box *P5C6=(Fl_Box *)0;
Fl_Box *P5C7=(Fl_Box *)0;
Fl_Text_Display *P5_hand_value=(Fl_Text_Display *)0;
Fl_Group *Player_6=(Fl_Group *)0;
Fl_Output *P6_Status=(Fl_Output *)0;
Fl_Text_Display *P6_Name=(Fl_Text_Display *)0;
Fl_Text_Display *P6_ID=(Fl_Text_Display *)0;
Fl_Text_Display *P6_clock=(Fl_Text_Display *)0;
Fl_Box *P6C1=(Fl_Box *)0;
Fl_Box *P6C2=(Fl_Box *)0;
Fl_Box *P6C3=(Fl_Box *)0;
Fl_Box *P6C4=(Fl_Box *)0;
Fl_Box *P6C5=(Fl_Box *)0;
Fl_Box *P6C6=(Fl_Box *)0;
Fl_Box *P6C7=(Fl_Box *)0;
Fl_Text_Display *P6_hand_value=(Fl_Text_Display *)0;
Fl_Group *Player_7=(Fl_Group *)0;
Fl_Output *P7_Status=(Fl_Output *)0;
Fl_Text_Display *P7_Name=(Fl_Text_Display *)0;
Fl_Text_Display *P7_ID=(Fl_Text_Display *)0;
Fl_Text_Display *P7_clock=(Fl_Text_Display *)0;
Fl_Box *P7C1=(Fl_Box *)0;
Fl_Box *P7C2=(Fl_Box *)0;
Fl_Box *P7C3=(Fl_Box *)0;
Fl_Box *P7C4=(Fl_Box *)0;
Fl_Box *P7C5=(Fl_Box *)0;
Fl_Box *P7C6=(Fl_Box *)0;
Fl_Box *P7C7=(Fl_Box *)0;
Fl_Text_Display *P7_hand_value=(Fl_Text_Display *)0;
Fl_Group *GUI_Dealer=(Fl_Group *)0;
Fl_Box *DC1=(Fl_Box *)0;
Fl_Box *DC2=(Fl_Box *)0;
Fl_Box *DC3=(Fl_Box *)0;
Fl_Box *DC4=(Fl_Box *)0;
Fl_Box *DC5=(Fl_Box *)0;
Fl_Box *DC6=(Fl_Box *)0;
Fl_Box *DC7=(Fl_Box *)0;
Fl_Text_Display *Suggestion_box=(Fl_Text_Display *)0;
Fl_Progress *shoe_bar=(Fl_Progress *)0;
Fl_Text_Buffer *P1NameBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P1IDBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P1ClockBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P1HandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P2NameBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P2IDBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P2ClockBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P2HandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P3NameBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P3IDBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P3ClockBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P3HandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P4NameBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P4IDBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P4ClockBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P4HandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P5NameBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P5IDBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P5ClockBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P5HandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P6NameBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P6IDBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P6ClockBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P6HandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P7NameBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P7IDBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P7ClockBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *P7HandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *duidBuffer=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *countBuff=(Fl_Text_Buffer *)0;
Fl_Text_Display *duid=(Fl_Text_Display *)0;
Fl_Text_Display *shoeTypeDisplay=(Fl_Text_Display *)0;
Fl_Text_Buffer *shoeTypeBuff=(Fl_Text_Buffer *)0;
Fl_Text_Display *countDisplay=(Fl_Text_Display *)0;
Fl_Text_Buffer *DHandBuff=(Fl_Text_Buffer *)0;
Fl_Text_Display *DHandDisplay=(Fl_Text_Display *)0;
Fl_Text_Buffer *suggestionBuff=(Fl_Text_Buffer *)0;
Fl_Text_Buffer *playersBuff=(Fl_Text_Buffer *)0;
Fl_Text_Display *playersDisplay=(Fl_Text_Display *)0;
Fl_Text_Buffer *statusBuff=(Fl_Text_Buffer *)0;
Fl_Text_Display *statusDisplay=(Fl_Text_Display *)0;
Fl_Choice *testSelector=(Fl_Choice *)0;
Fl_Button *testButton=(Fl_Button *)0;
Fl_Double_Window *testPopUp=(Fl_Double_Window *)0;

int test_shoe_type; //flag for what type of test shoe was selected

/////////////////////
///
///        CALLBACKS
///
/////////////////////

pthread_attr_t attr1;
pthread_attr_t attr2;

void test_selection(Fl_Widget *w, void *p)
{
	testPopUp->hide();
	test_shoe_type = (int)testSelector->value();
	if (test_shoe_type == 0)
	{
		run_tests();
		test_shoe_type++;
	}
	game->set_shoe(0);
	StartButton->show();
	return;
}

void test_suite(Fl_Widget *w, void *p)
{
	shoeTypeBuff->text("Test");
	start_botton_clicked = false;
	game_screen->show();
	open_screen->hide();
	shoe_bar->show();
	testPopUp->show();
	return;
}

void eight_shoe(Fl_Widget *w, void *p)
{
	game->set_shoe(1);
	shoeTypeBuff->text("8-Deck");
	game_screen->show();
	open_screen->hide();
	shoe_bar->show();
	pthread_attr_init(&attr1);
	pthread_t thread1;
	pthread_create(&thread1,&attr1, wait_for_players, NULL );
}

void infinite_shoe(Fl_Widget *w, void *p)
{
	game->set_shoe(2);
	shoeTypeBuff->text("Infinite");
	game_screen->show();
	open_screen->hide();
	pthread_attr_init(&attr1);
	pthread_t thread1;
	pthread_create(&thread1,&attr1, wait_for_players, NULL );
}

void start_game(Fl_Widget *w, void *p)
{
	if(start_botton_clicked == false)
	{
		start_botton_clicked = true;
		EndGame->show();
		StartButton->hide();
		if(game->shoe_type == 1)
		{
			pthread_attr_init(&attr2);
			pthread_t thread2;
			pthread_create(&thread2,&attr2, play_game, NULL );
		}else if(game->shoe_type == 0)
		{
			pthread_attr_init(&attr2);
			pthread_t thread2;
			pthread_create(&thread2,&attr2, test_game, NULL );
		}
	}
}

void next_hand(Fl_Widget *w, void *p)
{
	next_hand_f = true;
}

void deal_auto(Fl_Widget *w, void *p)
{
	NextHand->hide();
	DealAuto->hide();
	next_hand_f = true;
	auto_deal = true;
}

void end_game(Fl_Widget *w, void *p)
{
	game_over = true;
	delete game;
	delete P_rec;
	game_screen->hide();
	exit(0);
}

void publish_game()
{
	if(start_botton_clicked)
	{
		for(unsigned int i = 0;i < game->players.size();i++)
		{
			for(unsigned int k = 0; k< game->players[i].cards.size();k++ )
			{
				game->pstates[i].cards[k] = game->players[i].cards[k];
			}
			game->G_pub.p[i] = game->pstates[i];
		}
	}
	game->d_io->publish(game->D_pub);
	game->g_io->publish(game->G_pub);
	return;
}

void* wait_for_players( void *arg)
{
	game->G_pub.gstate = waiting_to_join;
	received_player_i = 0;
	start_botton_clicked = false;
	waiting_f = true;
	while(start_botton_clicked == false)
	{
		publish_game();//move to thread to publish over interval TODO
		while( received_player_i < P_rec->size())
		{
			pthread_mutex_lock(&mutex1);
			if( strncmp((*P_rec)[received_player_i].game_uid,game->G_pub.game_uid, SIZE_OF_UUID) == 0 )
			{
				bool exists = false;
				for(unsigned int k =0;k< game->players.size(); k++)
				{
					if( strncmp((*P_rec)[received_player_i].uid, game->players[k].P.uid, SIZE_OF_UUID) == 0 ) 
					{
						exists = true;
						break;
					}
				}
				if(exists == false)
				{
					if(game->players.size() == 0)
						StartButton->show();
					PlayerState pstate;
					memcpy( pstate.uid, &(*P_rec)[received_player_i].uid, sizeof ( pstate.uid ) );
					game->pstates.push_back( pstate );
					player_instance temp = player_instance((*P_rec)[received_player_i]);
					temp.player_num = (int)game->players.size();
					game->players.push_back(temp);
					set_players_gui(game->players.size());//set players gui enviornment
					pthread_mutex_unlock(&mutex1);
					received_player_i++;
					break;
				}
			}
			pthread_mutex_unlock(&mutex1);
			received_player_i++;
		}
		if(start_botton_clicked)
		{
			pthread_exit(0);
			break;
		}
	}
	pthread_exit(0);
}

string itos(int num)
{
	stringstream ss;
	ss << num;
	return ss.str();
}

void* play_game(void *arg)
{
	game->G_pub.gstate = playing;
	statusBuff->text( "Playing" );
	Fl::lock();
	game_screen->redraw();
	Fl::unlock();
	playing_f = true;
	bool action_rec = false;
	Player received_player;
	publish_game();
	time_t start;
	time_t now;
	while(game_over == false)
	{
		Fl::lock();
		NextHand->hide();
		Fl::unlock();
		game->deal_cards();
		Fl::lock();
		shoe_bar->value( (float)( 416 - game->shoe_iter ) );
		countBuff->text( itos( game->table_count ).c_str() );
		game->G_pub.active_player = (game->players.size() - 1);
		publish_game();
		Fl::check();
		Fl::unlock();
		hand vals = game->dealer_hand_value();
		bool D_won = false;
		if(vals.value.back() == 21)//Dealer wins Blackjack
		{
			string dwin21 = "Dealer wins with Blackjack.";
			suggestionBuff->text( dwin21.c_str() );
			D_won = true;
		}
		bool all_players_finished = true;
		while(game->G_pub.active_player >= 0 && D_won == false)
		{
			time(&start);
			time(&now);
			//if player has been booted, active will be false
			if(game->players[game->G_pub.active_player].active == false)
			{
				game->G_pub.active_player--;
				continue;
			}
			string playerSuggestedMove;
			hand current_value_check;
			current_value_check = game->players[game->G_pub.active_player].hand_value();
			if(current_value_check.value.back() == 21)//Player wins blackjack
			{
				stringstream winBJ;
				winBJ << "Player " << (game->G_pub.active_player + 1) << " wins Blackjack";
				playerSuggestedMove = winBJ.str();
				Fl::lock();
				suggestionBuff->text( playerSuggestedMove.c_str() );
				Fl::unlock();
				update_players_gui(game->G_pub.active_player);
				game->G_pub.active_player--;
				continue;
 			}
			if(game->G_pub.dealer_cards[1].card == ace)
			{
				playerSuggestedMove = game->players[game->G_pub.active_player].suggest_move( 11 );
			}
			else
			{
				playerSuggestedMove = game->players[game->G_pub.active_player].suggest_move( 
					(int)(game->G_pub.dealer_cards[1].card) );
			}
			Fl::lock();
			suggestionBuff->text( playerSuggestedMove.c_str() );
			Fl::unlock();
			action_rec = false;
			while( action_rec == false )
			{
				if(game->players[game->G_pub.active_player].clock - (int)(7 - (int)difftime(now,start)) != 0)
				{
					game->players[game->G_pub.active_player].clock = (int)(7 - difftime(now,start));
					update_players_gui(game->G_pub.active_player);
				}
				if( difftime(now,start) < 7 )//TODO change back to 7
				{
					if( action_f == true)
					{
						if( strncmp( (*P_rec).back().game_uid, game->G_pub.game_uid, SIZE_OF_UUID) == 0 )
						{
							if( strncmp((*P_rec).back().uid,game->G_pub.p[game->G_pub.active_player].uid,SIZE_OF_UUID)
								== 0 && (*P_rec).back().A != idle )
							{
								received_player = (*P_rec).back();
								player_rec = true;
								action_rec = true;
							}else
							{
								action_f = false;
							}
						}else
						{
							action_f = false;
						}
					}
					if(player_rec == true)
					{
						action_f = false;
						hand current_value;
						game->players[game->G_pub.active_player].clock = 7;
						game->players[game->G_pub.active_player].P.A = received_player.A;
						switch(received_player.A)
						{
							case idle :
								break;
							case hitting :
								printf("Player Hitting: %s\n",received_player.name);
								game->deal_one_card( (int)game->G_pub.active_player );
								Fl::lock();
								shoe_bar->value( (float)( 416 - game->shoe_iter ) );
								countBuff->text( itos( game->table_count ).c_str() );
								Fl::unlock();
								current_value = game->players[game->G_pub.active_player].hand_value();
								update_players_gui(game->G_pub.active_player);
								if(current_value.value.back() >= 21)
								{
									if(current_value.value.back() == 21)
									{
										if(game->players[game->G_pub.active_player].cards.size() == 2)
										//Player wins Blackjack
										{
											stringstream t_win21;
											t_win21 << "Player " << (game->G_pub.active_player +1)
											 << " wins Blackjack!";
											string win21 = t_win21.str();
											Fl::lock();
											suggestionBuff->text( win21.c_str() );
											Fl::unlock();
										}
										game->G_pub.active_player--;
									}else if(current_value.value.size() < 2)
									{
										update_players_gui(game->G_pub.active_player);
										game->G_pub.active_player--;
									}else if(current_value.value[0] > 21)
									{
										game->G_pub.active_player--;
									}						
								}
								break;
							case standing :
								printf("Player Standing: %s\n",received_player.name);
								update_players_gui(game->G_pub.active_player);
								all_players_finished = false;
								game->G_pub.active_player--;
								break;
							case doubling :
								printf("Player Doubling: %s\n",received_player.name);
								game->deal_one_card( (int)game->G_pub.active_player );
								Fl::lock();
								shoe_bar->value( (float)( 416 - game->shoe_iter ) );
								countBuff->text( itos( game->table_count ).c_str() );
								Fl::unlock();
								update_players_gui(game->G_pub.active_player);
								current_value = game->players[game->G_pub.active_player].hand_value();
								if(current_value.value[0] < 21)
								{
									all_players_finished = false;
								}	
								game->G_pub.active_player--;
								break;
							case splitting :
								break;
						}
						player_rec = false;
					}
				}else
				{
					for(unsigned int i = 0; i < game->players[game->G_pub.active_player].cards.size(); i++)
					{
						undisplay_cards(game->G_pub.active_player, i);
					}
					game->boot_player(game->G_pub.active_player);
					update_players_gui(game->G_pub.active_player);
					game->G_pub.active_player--;
					break;
				}
				time(&now);
			}
			publish_game();
		}
		game->G_pub.dealer_cards[0].valid = true;
		display_cards(7, 0, game->G_pub.dealer_cards[0]);
		update_players_gui(7);
		while(all_players_finished == false)
		{
			if( vals.value.back() < 22 && vals.value.back() > 17 )//dealer is done
			{
				break;
			}else if(vals.value.back() == 17 && vals.value.size() > 1 && vals.value[0] < 17)
			{
				game->deal_one_card(7);
				Fl::lock();
				shoe_bar->value( (float)( 416 - game->shoe_iter ) );
				countBuff->text( itos( game->table_count ).c_str() );
				Fl::unlock();
				update_players_gui(7);
				break;
			}else if(vals.value.back() > 21)
			{
				break;
			}else if(vals.value.back() < 17)
			{
				game->deal_one_card(7);
				Fl::lock();
				shoe_bar->value( (float)( 416 - game->shoe_iter ) );
				countBuff->text( itos( game->table_count ).c_str() );
				Fl::unlock();
				update_players_gui(7);
			}else
			{
				break;
			}
			vals = game->dealer_hand_value();
			sleep(1);//change to a mutex with publish_game TODO
			publish_game();
		}
		Fl::lock();
		NextHand->show();
		Fl::unlock();
		if(auto_deal == true)//will sleep for 2 seconds before next hand on auto
		{
			next_hand_f = true;
			sleep(2);
		}     
		while(next_hand_f == false ){ sleep(1); }
		next_hand_f = false; 
		game->clean_table();
		for(unsigned int i = 0;i< game->players.size(); i++)
		{
			if(game->players[i].active == false)
            	continue;
			game->players[i].P.A = idle;
			update_players_gui(i);
		}
		//Shuffle if <56 cards in deck
		if( (game->shoe_v.size() - game->shoe_iter ) <= 56)
		{
			//Display Shuffling & Completed an 8 deck shoe! TODO
			srand(time(0));
			random_shuffle(game->shoe_v.begin(),game->shoe_v.end() );
			game->shoe_iter = 0;
		}
		action_f = true;//removes deadlock condition
		pthread_mutex_lock(&mutex1);
		P_rec->clear();
		pthread_mutex_unlock(&mutex1);
		action_f = false;
		//Display new deck
	}
	return NULL;
}

void* test_game(void *arg)
{
	game->G_pub.gstate = playing;
	statusBuff->text( "Playing" );
	Fl::lock();
	game_screen->redraw();
	Fl::unlock();
	playing_f = true;
	bool action_rec = false;
	Player received_player;
	time_t start;
	time_t now;
	for(int i = 0;i < 7; i++)//Fills test game with Dummy Players
	{
		PlayerState state;
		sprintf(state.uid,"%d", (i+1) );
		game->pstates.push_back( state );
		Player tP;
		sprintf(tP.name,"Player-%d", (i+1) );
		player_instance temp = player_instance(tP);
		temp.player_num = (int)game->players.size();
		game->players.push_back(temp);
		set_players_gui(game->players.size());
	}
	while(game_over == false)
	{
		NextHand->hide();
		game->deal_cards();
		Fl::lock();
		shoe_bar->value( (float)( 416 - game->shoe_iter ) );
		countBuff->text( itos( game->table_count ).c_str() );
		Fl::unlock();
		game->G_pub.active_player = (game->players.size() - 1);
		hand vals = game->dealer_hand_value();
		bool D_won = false;
		if(vals.value.back() == 21)//Dealer wins Blackjack
		{
			string dwin21 = "Dealer wins with Blackjack.";
			Fl::lock();
			suggestionBuff->text( dwin21.c_str() );
			Fl::unlock();
			D_won = true;
		}
		int count = 0;
		bool all_players_finished = true;
		while(game->G_pub.active_player >= 0 && D_won == false)
		{
			time(&start);
			time(&now);//for testing
			//if player has been booted, active will be false
			if(game->players[game->G_pub.active_player].active == false)
			{
				game->G_pub.active_player--;
				continue;
			}
			string playerSuggestedMove;
			hand current_value_check;
			current_value_check = game->players[game->G_pub.active_player].hand_value();
			if(current_value_check.value.back() == 21)//Player wins blackjack
			{
				stringstream winBJ;
				winBJ << "Player " << (game->G_pub.active_player + 1) << " wins Blackjack";
				playerSuggestedMove = winBJ.str();
				Fl::lock();
				suggestionBuff->text( playerSuggestedMove.c_str() );
				Fl::unlock();
				update_players_gui(game->G_pub.active_player);
				game->G_pub.active_player--;
				continue;
 			}
 			if(test_shoe_type < 9)
 			{
 				if(game->G_pub.dealer_cards[1].card == ace)
				{
					playerSuggestedMove = game->players[game->G_pub.active_player].suggest_move( 11 );
				}
				else
				{
					playerSuggestedMove = game->players[game->G_pub.active_player].suggest_move( 
						(int)(game->G_pub.dealer_cards[1].card) );
				}
 			}
			Fl::lock();
			suggestionBuff->text( playerSuggestedMove.c_str() );
			Fl::unlock();
			action_rec = false;
			while( action_rec == false )
			{
				if(game->players[game->G_pub.active_player].clock - (int)(7 - (int)difftime(now,start)) != 0)
				{
					game->players[game->G_pub.active_player].clock = (int)(7 - difftime(now,start));
					update_players_gui(game->G_pub.active_player);
				}
				if( difftime(now,start) < 7 )//TODO change back to 7
				{
					/*if( action_f == true)
					{
						if( strncmp( (*P_rec).back().game_uid, game->G_pub.game_uid, SIZE_OF_UUID) == 0 )
						{
							if( strncmp((*P_rec).back().uid,game->G_pub.p[game->G_pub.active_player].uid,SIZE_OF_UUID)
								== 0 && (*P_rec).back().A != idle )
							{
								received_player = (*P_rec).back();
								player_rec = true;
								action_rec = true;
							}else
							{
								action_f = false;
							}
						}else
						{
							action_f = false;
						}
					}*/
					if(test_shoe_type > 0 && test_shoe_type <=6)
					{
						received_player.A = standing;
					}else if(test_shoe_type == 7)
					{
						received_player.A = hitting;
					}else if(test_shoe_type == 8)
					{
						received_player.A = doubling;
					}else if(test_shoe_type == 9)
					{
						count++;
						received_player.A = hitting;
						if(count == 6)
							received_player.A = standing;
					}else if(test_shoe_type == 10)
					{
						count++;
						received_player.A = hitting;
					}
					strncpy(received_player.name, game->players[game->G_pub.active_player].P.name,sizeof(received_player.name) );
					player_rec = true;
					action_rec = true;
					if(player_rec == true)
					{
						action_f = false;
						hand current_value;
						game->players[game->G_pub.active_player].clock = 7;
						game->players[game->G_pub.active_player].P.A = received_player.A;
						switch(received_player.A)
						{
							case idle :
								break;
							case hitting :
								printf("Player Hitting: %s\n",received_player.name);
								game->deal_one_card( (int)game->G_pub.active_player );
								Fl::lock();
								shoe_bar->value( (float)( 416 - game->shoe_iter ) );
								countBuff->text( itos( game->table_count ).c_str() );
								Fl::unlock();
								current_value = game->players[game->G_pub.active_player].hand_value();
								update_players_gui(game->G_pub.active_player);
								if(current_value.value.back() >= 21)
								{
									if(current_value.value.back() == 21)
									{
										if(game->players[game->G_pub.active_player].cards.size() == 2)
										//Player wins Blackjack
										{
											stringstream t_win21;
											t_win21 << "Player " << (game->G_pub.active_player +1)
											 << " wins Blackjack!";
											string win21 = t_win21.str();
											Fl::lock();
											suggestionBuff->text( win21.c_str() );
											Fl::unlock();
										}
										game->G_pub.active_player--;
										count = 0;
									}else if(current_value.value.size() < 2)
									{
										update_players_gui(game->G_pub.active_player);
										game->G_pub.active_player--;
									}else if(current_value.value[0] > 21)
									{
										game->G_pub.active_player--;
										count = 0;
									}						
								}
								break;
							case standing :
								printf("Player Standing: %s\n",received_player.name);
								update_players_gui(game->G_pub.active_player);
								all_players_finished = false;
								game->G_pub.active_player--;
								count = 0;
								break;
							case doubling :
								printf("Player Doubling: %s\n",received_player.name);
								game->deal_one_card( (int)game->G_pub.active_player );
								Fl::lock();
								shoe_bar->value( (float)( 416 - game->shoe_iter ) );
								countBuff->text( itos( game->table_count ).c_str() );
								Fl::unlock();
								update_players_gui(game->G_pub.active_player);
								current_value = game->players[game->G_pub.active_player].hand_value();
								if(current_value.value[0] < 21)
								{
									all_players_finished = false;
								}	
								game->G_pub.active_player--;
								break;
							case splitting :
								break;
						}
						player_rec = false;
					}
				}else
				{
					for(unsigned int i = 0; i < game->players[game->G_pub.active_player].cards.size(); i++)
					{
						undisplay_cards(game->G_pub.active_player, i);
					}
					game->boot_player(game->G_pub.active_player);
					update_players_gui(game->G_pub.active_player);
					game->G_pub.active_player--;
					break;
				}
				time(&now);
			}
		}
		game->G_pub.dealer_cards[0].valid = true;
		display_cards(7, 0, game->G_pub.dealer_cards[0]);
		update_players_gui(7);
		while(all_players_finished == false)
		{
			if( vals.value.back() < 22 && vals.value.back() > 17 )//dealer is done
			{
				break;
			}else if(vals.value.back() == 17 && vals.value.size() > 1 && vals.value[0] < 17)
			{
				game->deal_one_card(7);
				Fl::lock();
				shoe_bar->value( (float)( 416 - game->shoe_iter ) );
				countBuff->text( itos( game->table_count ).c_str() );
				Fl::unlock();
				update_players_gui(7);
				break;
			}else if(vals.value.back() > 21)
			{
				break;
			}else if(vals.value.back() < 17)
			{
				game->deal_one_card(7);
				Fl::lock();
				shoe_bar->value( (float)( 416 - game->shoe_iter ) );
				countBuff->text( itos( game->table_count ).c_str() );
				Fl::unlock();
				update_players_gui(7);
			}else
			{
				break;
			}
			vals = game->dealer_hand_value();
		} 
		Fl::lock();
		NextHand->show();
		Fl::unlock();
		if(auto_deal == true)//will sleep for 2 seconds before next hand on auto
		{
			next_hand_f = true;
			sleep(2);
		}     
		while(next_hand_f == false ){ sleep(1); }
		next_hand_f = false; 
		game->clean_table();
		for(unsigned int i = 0;i< game->players.size(); i++)
		{
			if(game->players[i].active == false)
            	continue;
			game->players[i].P.A = idle;
			update_players_gui(i);
		}
		//Shuffle if <46 cards in deck -- Modified for testing
		if( (game->shoe_v.size() - game->shoe_iter ) <= 56)
		{
			game->shoe_iter = 0;//keeps the same shoe
		}
		action_f = true;//removes deadlock condition
		pthread_mutex_lock(&mutex1);
		P_rec->clear();
		pthread_mutex_unlock(&mutex1);
		action_f = false;
		//Display new deck
	}
	return NULL;
}

void update_players_gui(int x)
{
	//set gui environment
	Fl::lock();
	stringstream tempstring;
	tempstring << game->players.size();
	string playersString = tempstring.str();
	playersBuff->text(playersString.c_str());
	char text_handvalue[50],clock_val[50];
	if(x != 7)
		sprintf(text_handvalue,"%d",game->players[x].hand_value().value.back());
	
	sprintf(clock_val,"%d",game->players[x].clock);
	x++;
	switch ( x )
	{
		case 1 :
			P1ClockBuff->text( clock_val );
			P1HandBuff->text( text_handvalue );
			if(game->players[ 0 ].active == false)
				P1_Status->value( "   Removed" );
			else
				P1_Status->value( to_string( game->players[0].P.A ).c_str() );
			
			game_screen->redraw();
			break;
		case 2 : 
			P2ClockBuff->text( clock_val );
			P2HandBuff->text( text_handvalue );
			if(game->players[ 1 ].active == false)
				P2_Status->value( "   Removed" );
			else
				P2_Status->value( to_string( game->players[1].P.A ).c_str() );
			
			game_screen->redraw();
			break;
		case 3 : 
			P3ClockBuff->text( clock_val );
			P3HandBuff->text( text_handvalue );
			if(game->players[ 2 ].active == false)
				P3_Status->value( "   Removed" );
			else
				P3_Status->value( to_string( game->players[2].P.A ).c_str() );
			
			game_screen->redraw();
			break;
		case 4 : 
			P4ClockBuff->text( clock_val );
			P4HandBuff->text( text_handvalue );
			if(game->players[ 3 ].active == false)
				P4_Status->value( "   Removed" );
			else
				P4_Status->value( to_string( game->players[3].P.A ).c_str() );
			
			game_screen->redraw();
			break;
		case 5 : 
			P5ClockBuff->text( clock_val );
			P5HandBuff->text( text_handvalue );
			if(game->players[ 4 ].active == false)
				P5_Status->value( "   Removed" );
			else
				P5_Status->value( to_string( game->players[4].P.A ).c_str() );
			
			game_screen->redraw();
			break;
		case 6 : 
			P6ClockBuff->text( clock_val );
			P6HandBuff->text( text_handvalue );
			if(game->players[ 5 ].active == false)
				P6_Status->value( "   Removed" );
			else
				P6_Status->value( to_string( game->players[5].P.A ).c_str() );
			
			game_screen->redraw();
			break;
		case 7 : 
			P7ClockBuff->text( clock_val );
			P7HandBuff->text( text_handvalue );
			if(game->players[ 6 ].active == false)
				P7_Status->value( "   Removed" );
			else
				P7_Status->value( to_string( game->players[6].P.A ).c_str() );
			
			game_screen->redraw();
			break;
		case 8 :
			sprintf(text_handvalue,"%d",game->dealer_hand_value().value.back());
			DHandBuff->text( text_handvalue );
			game_screen->redraw();
			break;
	}
	Fl::check();
	Fl::unlock();
}

void set_players_gui(int x)
{
	//set gui environment
	stringstream tempstring;
	tempstring << game->players.size();
	string playersString = tempstring.str();
	Fl::lock();
	playersBuff->text(playersString.c_str());
	string name = game->players[x-1].name;
	switch ( x )
	{
		case 1 :
			P1NameBuff->text( name.c_str() );
			P1ClockBuff->text( "7" );
			P1HandBuff->text( "0" );
			P1_Status->value( to_string( game->players[0].P.A ).c_str() );
			game_screen->redraw();
			break;
		case 2 : 
			P2NameBuff->text( name.c_str() );
			P2ClockBuff->text( "7" );
			P2HandBuff->text( "0" );
			P2_Status->value( to_string( game->players[1].P.A ).c_str() );
			game_screen->redraw();
			break;
		case 3 : 
			P3NameBuff->text( name.c_str() );
			P3ClockBuff->text( "7" );
			P3HandBuff->text( "0" );
			P3_Status->value( to_string( game->players[2].P.A ).c_str() );
			game_screen->redraw();
			break;
		case 4 : 
			P4NameBuff->text( name.c_str() );
			P4ClockBuff->text( "7" );
			P4HandBuff->text( "0" );
			P4_Status->value( to_string( game->players[3].P.A ).c_str() );
			game_screen->redraw();
			break;
		case 5 : 
			P5NameBuff->text( name.c_str() );
			P5ClockBuff->text( "7" );
			P5HandBuff->text( "0" );
			P5_Status->value( to_string( game->players[4].P.A ).c_str() );
			game_screen->redraw();
			break;
		case 6 : 
			P6NameBuff->text( name.c_str() );
			P6ClockBuff->text( "7" );
			P6HandBuff->text( "0" );
			P6_Status->value( to_string( game->players[5].P.A ).c_str() );
			game_screen->redraw();
			break;
		case 7 : 
			P7NameBuff->text( name.c_str() );
			P7ClockBuff->text( "7" );
			P7HandBuff->text( "0" );
			P7_Status->value( to_string( game->players[6].P.A ).c_str() );
			game_screen->redraw();
			break;
	}
	Fl::check();
	Fl::unlock();
}

void undisplay_cards(int playerIndex, int cardIndex)
{
	Fl::lock();
	switch ( playerIndex )
	{
		case 0 : //player 1
			switch ( cardIndex )
			{
				case 0 : //card 1
					P1C1->hide();
					break;
				case 1 : //card 2
					P1C2->hide();
					break;
				case 2 : //card 3
					P1C3->hide();
					break;
				case 3 : //card 4
					P1C4->hide();
					break;
				case 4 : //card 5
					P1C5->hide();
					break;
				case 5 : //card 6
					P1C6->hide();
					break;
				case 6 : //card 7
					P1C7->hide();
					break;
			}
			break;
		case 1 : //player 2
			switch ( cardIndex )
			{
				case 0 : //card 1
					P2C1->hide();
					break;
				case 1 : //card 2
					P2C2->hide();
					break;
				case 2 : //card 3
					P2C3->hide();
					break;
				case 3 : //card 4
					P2C4->hide();
					break;
				case 4 : //card 5
					P2C5->hide();
					break;
				case 5 : //card 6
					P2C6->hide();
					break;
				case 6 : //card 7
					P2C7->hide();
					break;
			}
			break;
		case 2 : //player 3
			switch ( cardIndex )
			{
				case 0 : //card 1
					P3C1->hide();
					break;
				case 1 : //card 2
					P3C2->hide();
					break;
				case 2 : //card 3
					P3C3->hide();
					break;
				case 3 : //card 4
					P3C4->hide();
					break;
				case 4 : //card 5
					P3C5->hide();
					break;
				case 5 : //card 6
					P3C6->hide();
					break;
				case 6 : //card 7
					P3C7->hide();
					break;
			}
			break;
		case 3 : //player 4
			switch ( cardIndex )
			{
				case 0 : //card 1
					P4C1->hide();
					break;
				case 1 : //card 2
					P4C2->hide();
					break;
				case 2 : //card 3
					P4C3->hide();
					break;
				case 3 : //card 4
					P4C4->hide();
					break;
				case 4 : //card 5
					P4C5->hide();
					break;
				case 5 : //card 6
					P4C6->hide();
					break;
				case 6 : //card 7
					P4C7->hide();
					break;
			}
			break;
		case 4 : //player 5
			switch ( cardIndex )
			{
				case 0 : //card 1
					P5C1->hide();
					break;
				case 1 : //card 2
					P5C2->hide();
					break;
				case 2 : //card 3
					P5C3->hide();
					break;
				case 3 : //card 4
					P5C4->hide();
					break;
				case 4 : //card 5
					P5C5->hide();
					break;
				case 5 : //card 6
					P5C6->hide();
					break;
				case 6 : //card 7
					P5C7->hide();
					break;
			}
			break;
		case 5 : //player 6
			switch ( cardIndex )
			{
				case 0 : //card 1
					P6C1->hide();
					break;
				case 1 : //card 2
					P6C2->hide();
					break;
				case 2 : //card 3
					P6C3->hide();
					break;
				case 3 : //card 4
					P6C4->hide();
					break;
				case 4 : //card 5
					P6C5->hide();
					break;
				case 5 : //card 6
					P6C6->hide();
					break;
				case 6 : //card 7
					P6C7->hide();
					break;
			}
			break;
		case 6 : //player 7
			switch ( cardIndex )
			{
				case 0 : //card 1
					P7C1->hide();
					break;
				case 1 : //card 2
					P7C2->hide();
					break;
				case 2 : //card 3
					P7C3->hide();
					break;
				case 3 : //card 4
					P7C4->hide();
					break;
				case 4 : //card 5
					P7C5->hide();
					break;
				case 5 : //card 6
					P7C6->hide();
					break;
				case 6 : //card 7
					P7C7->hide();
					break;
			}
			break;
		case 7 : //Dealer
			switch ( cardIndex )
			{
				case 0 : //card 1
					DC1->hide();
					break;
				case 1 : //card 2
					DC2->hide();
					break;
				case 2 : //card 3
					DC3->hide();
					break;
				case 3 : //card 4
					DC4->hide();
					break;
				case 4 : //card 5
					DC5->hide();
					break;
				case 5 : //card 6
					DC6->hide();
					break;
				case 6 : //card 7
					DC7->hide();
					break;
			}
			break;
	}
	Fl::unlock();
}

void display_cards(int playerIndex, int cardIndex, card_t card)
{
	Fl::lock();
	Fl_Box *widget;
	switch ( playerIndex )
	{
		case 0 : //Player 1
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = P1C1;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 1 : //card 2
					widget = P1C2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = P1C3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = P1C4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = P1C5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = P1C6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = P1C7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			
			break;
		case 1 : //Player 2
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = P2C1;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 1 : //card 2
					widget = P2C2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = P2C3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = P2C4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = P2C5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = P2C6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = P2C7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			break;
		case 2 : //Player 3
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = P3C1;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 1 : //card 2
					widget = P3C2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = P3C3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = P3C4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = P3C5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = P3C6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = P3C7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			break;
		case 3 : //Player 4
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = P4C1;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 1 : //card 2
					widget = P4C2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = P4C3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = P4C4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = P4C5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = P4C6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = P4C7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			break;
		case 4 : //Player 5
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = P5C1;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 1 : //card 2
					widget = P5C2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = P5C3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = P5C4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = P5C5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = P5C6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = P5C7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			break;
		case 5 : //Player 6
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = P6C1;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 1 : //card 2
					widget = P6C2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = P6C3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = P6C4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = P6C5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = P6C6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = P6C7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			break;
		case 6 : //Player 7
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = P7C1;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 1 : //card 2
					widget = P7C2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = P7C3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = P7C4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = P7C5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = P7C6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = P7C7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			break;
		case 7 : //Dealer
			switch ( cardIndex )
			{
				case 0 : //card 1
					widget = DC1;
					if(card.valid == false)
					{
						widget->image( new Fl_PNG_Image( "../cards/gray_back.png" ) );
						widget->show();
					}else
					{
						switch ( card.suite )
						{
							case hearts :
								switch ( card.card )
								{
									case ace :
										widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
										widget->show();
										break;
									case two :
										widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
										widget->show();
										break;
									case three :
										widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
										widget->show();
										break;
									case four :
										widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
										widget->show();
										break;
									case five :
										widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
										widget->show();
										break;
									case six :
										widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
										widget->show();
										break;
									case seven :
										widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
										widget->show();
										break;
									case eight :
										widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
										widget->show();
										break;
									case nine :
										widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
										widget->show();
										break;
									case ten :
										widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
										widget->show();
										break;
									case jack :
										widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
										widget->show();
										break;
									case queen :
										widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
										widget->show();
										break;
									case king :
										widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
										widget->show();
										break;
								}
								break;
							case diamonds :
								switch ( card.card )
								{
									case ace :
										widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
										widget->show();
										break;
									case two :
										widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
										widget->show();
										break;
									case three :
										widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
										widget->show();
										break;
									case four :
										widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
										widget->show();
										break;
									case five :
										widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
										widget->show();
										break;
									case six :
										widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
										widget->show();
										break;
									case seven :
										widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
										widget->show();
										break;
									case eight :
										widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
										widget->show();
										break;
									case nine :
										widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
										widget->show();
										break;
									case ten :
										widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
										widget->show();
										break;
									case jack :
										widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
										widget->show();
										break;
									case queen :
										widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
										widget->show();
										break;
									case king :
										widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
										widget->show();
										break;
								}
								break;
							case clubs :
								switch ( card.card )
								{
									case ace :
										widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
										widget->show();
										break;
									case two :
										widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
										widget->show();
										break;
									case three :
										widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
										widget->show();
										break;
									case four :
										widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
										widget->show();
										break;
									case five :
										widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
										widget->show();
										break;
									case six :
										widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
										widget->show();
										break;
									case seven :
										widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
										widget->show();
										break;
									case eight :
										widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
										widget->show();
										break;
									case nine :
										widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
										widget->show();
										break;
									case ten :
										widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
										widget->show();
										break;
									case jack :
										widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
										widget->show();
										break;
									case queen :
										widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
										widget->show();
										break;
									case king :
										widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
										widget->show();
										break;
								}
								break;
							case spades :
								switch ( card.card )
								{
									case ace :
										widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
										widget->show();
										break;
									case two :
										widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
										widget->show();
										break;
									case three :
										widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
										widget->show();
										break;
									case four :
										widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
										widget->show();
										break;
									case five :
										widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
										widget->show();
										break;
									case six :
										widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
										widget->show();
										break;
									case seven :
										widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
										widget->show();
										break;
									case eight :
										widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
										widget->show();
										break;
									case nine :
										widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
										widget->show();
										break;
									case ten :
										widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
										widget->show();
										break;
									case jack :
										widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
										widget->show();
										break;
									case queen :
										widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
										widget->show();
										break;
									case king :
										widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
										widget->show();
										break;
								}
								break;
						}
					}
					break;
				case 1 : //card 2
					widget = DC2;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 2 : //card 3
					widget = DC3;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 3 : //card 4
					widget = DC4;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 4 : //card 5
					widget = DC5;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 5 : //card 6
					widget = DC6;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
				case 6 : //card 7
					widget = DC7;
					switch ( card.suite )
					{
						case hearts :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AH.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2H.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3H.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4H.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5H.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6H.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7H.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8H.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9H.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10H.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JH.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QH.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KH.png" ) );
									widget->show();
									break;
							}
							break;
						case diamonds :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AD.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2D.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3D.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4D.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5D.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6D.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7D.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8D.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9D.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10D.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JD.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QD.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KD.png" ) );
									widget->show();
									break;
							}
							break;
						case clubs :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AC.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2C.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3C.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4C.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5C.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6C.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7C.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8C.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9C.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10C.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JC.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QC.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KC.png" ) );
									widget->show();
									break;
							}
							break;
						case spades :
							switch ( card.card )
							{
								case ace :
									widget->image( new Fl_PNG_Image( "../cards/AS.png" ) );
									widget->show();
									break;
								case two :
									widget->image( new Fl_PNG_Image( "../cards/2S.png" ) );
									widget->show();
									break;
								case three :
									widget->image( new Fl_PNG_Image( "../cards/3S.png" ) );
									widget->show();
									break;
								case four :
									widget->image( new Fl_PNG_Image( "../cards/4S.png" ) );
									widget->show();
									break;
								case five :
									widget->image( new Fl_PNG_Image( "../cards/5S.png" ) );
									widget->show();
									break;
								case six :
									widget->image( new Fl_PNG_Image( "../cards/6S.png" ) );
									widget->show();
									break;
								case seven :
									widget->image( new Fl_PNG_Image( "../cards/7S.png" ) );
									widget->show();
									break;
								case eight :
									widget->image( new Fl_PNG_Image( "../cards/8S.png" ) );
									widget->show();
									break;
								case nine :
									widget->image( new Fl_PNG_Image( "../cards/9S.png" ) );
									widget->show();
									break;
								case ten :
									widget->image( new Fl_PNG_Image( "../cards/10S.png" ) );
									widget->show();
									break;
								case jack :
									widget->image( new Fl_PNG_Image( "../cards/JS.png" ) );
									widget->show();
									break;
								case queen :
									widget->image( new Fl_PNG_Image( "../cards/QS.png" ) );
									widget->show();
									break;
								case king :
									widget->image( new Fl_PNG_Image( "../cards/KS.png" ) );
									widget->show();
									break;
							}
							break;
					}
					break;
			}
			break;
	}
	Fl::unlock();
}


