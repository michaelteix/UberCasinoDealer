//  Created by Kyle Teixeira on 4/4/18.
#ifndef gui_h
#define gui_h

#include <GL/glx.h>
#include <GL/gl.h>
#include <X11/X.h>
#include <X11/keysym.h>

/////////////////////////////
// FLTK WIDGET DECLARATIONS
/////////////////////////////

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_PNG_Image.H>
#include "test_suite.h"
#include <Fl/Fl_Choice.H>
#include <Fl/x.H>

using namespace std; 
	
extern game_instance *game;
extern Fl_Double_Window* open_screen;
extern Fl_Double_Window* game_screen;
extern Fl_Double_Window *testPopUp;

extern Fl_Box *background;
extern Fl_Button *Title;
extern Fl_Button *NextHand;
extern Fl_Button *DealAuto;
extern Fl_Button *StartButton;
extern Fl_Button *EndGame;
extern Fl_Group *Players;
extern Fl_Group *Player_1;
extern Fl_Output *P1_Status;
extern Fl_Text_Display *P1_Name;
extern Fl_Text_Display *P1_ID;
extern Fl_Text_Display *P1_clock;
extern Fl_Box *P1C1;
extern Fl_Box *P1C2;
extern Fl_Box *P1C3;
extern Fl_Box *P1C4;
extern Fl_Box *P1C5;
extern Fl_Box *P1C6;
extern Fl_Box *P1C7;
extern Fl_Text_Display *P1_hand_value;
extern Fl_Group *Player_2;
extern Fl_Output *P2_Status;
extern Fl_Text_Display *P2_Name;
extern Fl_Text_Display *P2_ID;
extern Fl_Text_Display *P2_clock;
extern Fl_Box *P2C1;
extern Fl_Box *P2C2;
extern Fl_Box *P2C3;
extern Fl_Box *P2C4;
extern Fl_Box *P2C5;
extern Fl_Box *P2C6;
extern Fl_Box *P2C7;
extern Fl_Text_Display *P2_hand_value;
extern Fl_Group *Player_3;
extern Fl_Output *P3_Status;
extern Fl_Text_Display *P3_Name;
extern Fl_Text_Display *P3_ID;
extern Fl_Text_Display *P3_clock;
extern Fl_Box *P3C1;
extern Fl_Box *P3C2;
extern Fl_Box *P3C3;
extern Fl_Box *P3C4;
extern Fl_Box *P3C5;
extern Fl_Box *P3C6;
extern Fl_Box *P3C7;
extern Fl_Text_Display *P3_hand_value;
extern Fl_Group *Player_4;
extern Fl_Output *P4_Status;
extern Fl_Text_Display *P4_Name;
extern Fl_Text_Display *P4_ID;
extern Fl_Text_Display *P4_clock;
extern Fl_Box *P4C1;
extern Fl_Box *P4C2;
extern Fl_Box *P4C3;
extern Fl_Box *P4C4;
extern Fl_Box *P4C5;
extern Fl_Box *P4C6;
extern Fl_Box *P4C7;
extern Fl_Text_Display *P4_hand_value;
extern Fl_Group *Player_5;
extern Fl_Output *P5_Status;
extern Fl_Text_Display *P5_Name;
extern Fl_Text_Display *P5_ID;
extern Fl_Text_Display *P5_clock;
extern Fl_Box *P5C1;
extern Fl_Box *P5C2;
extern Fl_Box *P5C3;
extern Fl_Box *P5C4;
extern Fl_Box *P5C5;
extern Fl_Box *P5C6;
extern Fl_Box *P5C7;
extern Fl_Text_Display *P5_hand_value;
extern Fl_Group *Player_6;
extern Fl_Output *P6_Status;
extern Fl_Text_Display *P6_Name;
extern Fl_Text_Display *P6_ID;
extern Fl_Text_Display *P6_clock;
extern Fl_Box *P6C1;
extern Fl_Box *P6C2;
extern Fl_Box *P6C3;
extern Fl_Box *P6C4;
extern Fl_Box *P6C5;
extern Fl_Box *P6C6;
extern Fl_Box *P6C7;
extern Fl_Text_Display *P6_hand_value;
extern Fl_Group *Player_7;
extern Fl_Output *P7_Status;
extern Fl_Text_Display *P7_Name;
extern Fl_Text_Display *P7_ID;
extern Fl_Text_Display *P7_clock;
extern Fl_Box *P7C1;
extern Fl_Box *P7C2;
extern Fl_Box *P7C3;
extern Fl_Box *P7C4;
extern Fl_Box *P7C5;
extern Fl_Box *P7C6;
extern Fl_Box *P7C7;
extern Fl_Text_Display *P7_hand_value;
extern Fl_Group *GUI_Dealer;
extern Fl_Box *DC1;
extern Fl_Box *DC2;
extern Fl_Box *DC3;
extern Fl_Box *DC4;
extern Fl_Box *DC5;
extern Fl_Box *DC6;
extern Fl_Box *DC7;
extern Fl_Text_Display *Suggestion_box;
extern Fl_Progress *shoe_bar;
extern Fl_Text_Buffer *P1NameBuff;
extern Fl_Text_Buffer *P1IDBuff;
extern Fl_Text_Buffer *P1ClockBuff;
extern Fl_Text_Buffer *P1HandBuff;
extern Fl_Text_Buffer *P2NameBuff;
extern Fl_Text_Buffer *P2IDBuff;
extern Fl_Text_Buffer *P2ClockBuff;
extern Fl_Text_Buffer *P2HandBuff;
extern Fl_Text_Buffer *P3NameBuff;
extern Fl_Text_Buffer *P3IDBuff;
extern Fl_Text_Buffer *P3ClockBuff;
extern Fl_Text_Buffer *P3HandBuff;
extern Fl_Text_Buffer *P4NameBuff;
extern Fl_Text_Buffer *P4IDBuff;
extern Fl_Text_Buffer *P4ClockBuff;
extern Fl_Text_Buffer *P4HandBuff;
extern Fl_Text_Buffer *P5NameBuff;
extern Fl_Text_Buffer *P5IDBuff;
extern Fl_Text_Buffer *P5ClockBuff;
extern Fl_Text_Buffer *P5HandBuff;
extern Fl_Text_Buffer *P6NameBuff;
extern Fl_Text_Buffer *P6IDBuff;
extern Fl_Text_Buffer *P6ClockBuff;
extern Fl_Text_Buffer *P6HandBuff;
extern Fl_Text_Buffer *P7NameBuff;
extern Fl_Text_Buffer *P7IDBuff;
extern Fl_Text_Buffer *P7ClockBuff;
extern Fl_Text_Buffer *P7HandBuff;
extern Fl_Text_Buffer *duidBuffer;
extern Fl_Text_Buffer *shoeTypeBuff;
extern Fl_Text_Buffer *countBuff;
extern Fl_Text_Display *duid;
extern Fl_Text_Display *shoeTypeDisplay;
extern Fl_Text_Display *countDisplay;
extern Fl_Text_Buffer *DHandBuff;
extern Fl_Text_Display *DHandDisplay;
extern Fl_Text_Buffer *suggestionBuff;
extern Fl_Text_Buffer *playersBuff;
extern Fl_Text_Display *playersDisplay;
extern Fl_Text_Buffer *statusBuff;
extern Fl_Text_Display *statusDisplay;
extern Fl_Choice *testSelector;
extern Fl_Button *testButton;

/////////////////////
///
///	GLOBAL FUNCTIONS
///
/////////////////////

void update_players_gui(int x);
void set_players_gui(int x);
void publish_game();
string itos(int num);
void* play_game(void *arg);
void* test_game(void *arg);
string itos(int num);
void* wait_for_players(void *arg);
void undisplay_cards(int playerIndex, int cardIndex);
void display_cards(int playerIndex, int cardIndex, card_t card);

/////////////////////
///
///    CALLBACKS
///
/////////////////////
	
void test_selection(Fl_Widget *w, void *p);
void test_suite(Fl_Widget *w, void *p);
void eight_shoe(Fl_Widget *w, void *p);
void infinite_shoe(Fl_Widget *w, void *p);
void start_game(Fl_Widget *w, void *p);
void end_game(Fl_Widget *w, void *p);
void next_hand(Fl_Widget *w, void *p);
void deal_auto(Fl_Widget *w, void *p);

#endif /* gui_h */
