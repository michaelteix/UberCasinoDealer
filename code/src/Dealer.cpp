#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include "gui.h"

typedef boost::uuids::uuid UID;
UID new_uuid() 
{
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    return uuid;
}

Fl_Double_Window* game_screen;
Fl_Double_Window* open_screen;
Fl_PNG_Image *background_image;
Fl_Button *NextHand;
Fl_Button *DealAuto;
Fl_Button *StartButton;
Fl_Button *EndGame;
game_instance *game = new game_instance();

using namespace std;

std::string to_string ( UberCasino::game_state t );
    
int main( int argc, char *argv[] )
{	
    ////////////////////////////////////
    ///////
    //////  Begin Main Execution
    ///////
    ////////////////////////////////////
    playing_f = false;
	action_f = false;
	waiting_f = false;
	srand(time(0));
	//XInitThreads();
	
    // dealer unique ID
   	UID uuid = new_uuid();
   	memcpy ( game->D_pub.uid, &uuid, sizeof ( char ) * SIZE_OF_UUID );
   	memcpy ( game->G_pub.dealer_uid, &uuid, sizeof ( char ) * SIZE_OF_UUID );
   	strncpy ( game->D_pub.name,"Teixeira",sizeof ( game->D_pub.name ) );
    
    // game unique ID
   	UID game_uuid = new_uuid();
   	memcpy ( game->G_pub.game_uid, &game_uuid, SIZE_OF_UUID );
   	memcpy ( game->D_pub.game_uid, &game_uuid, sizeof ( char ) * SIZE_OF_UUID );
   	//GENERATE WINDOW
	
	background_image = new Fl_PNG_Image("background_950x550.png");
	{
	    Fl_Double_Window* o = new Fl_Double_Window(995, 605);
	    open_screen = o;
	    o->box(FL_DOWN_BOX);
	    {
	        Fl_Return_Button* o = new Fl_Return_Button(350, 415, 290, 105, "8-Deck Shoe");
	        o->box(FL_SHADOW_BOX);
	        o->color((Fl_Color)61);
	        o->labelfont(14);
	        o->labelsize(25);
	        o->labelcolor(FL_BACKGROUND2_COLOR);
	        o->callback( (Fl_Callback *)eight_shoe );
	    } // Fl_Return_Button* o
	    {
	        Fl_Box* o = new Fl_Box(75, 30, 820, 240, "UberCasino");
	        o->labelfont(7);
	        o->labelsize(150);
	        o->labelcolor((Fl_Color)178);
	    } // Fl_Box* o
	    {
	        Fl_Box* o = new Fl_Box(440, 245, 100, 25, "Dealer Version");
	        o->labelsize(51);
	        o->labelcolor((Fl_Color)178);
	    } // Fl_Box* o
	    {
	        Fl_Button* o = new Fl_Button(645, 415, 290, 105, "Infinite Shoe");
	        o->box(FL_SHADOW_BOX);
	        o->color((Fl_Color)69);
	        o->labelfont(14);
	        o->labelsize(25);
	        o->labelcolor((Fl_Color)89);
	        o->callback( (Fl_Callback *)infinite_shoe );
	    } // Fl_Button* o
	    {
	        Fl_Button* o = new Fl_Button(55, 415, 290, 105, "Test Mode");
	        o->box(FL_SHADOW_BOX);
	        o->color((Fl_Color)38);
	        o->labelfont(14);
	        o->labelsize(25);
	        o->callback( (Fl_Callback *)test_suite );
	    } // Fl_Button* o
	    {
	        Fl_Box* o = new Fl_Box(330, 350, 325, 45, "Host a Table");
	        o->labeltype(FL_ENGRAVED_LABEL);
	        o->labelsize(35);
	    } // Fl_Box* o
	    o->end();
	} // Fl_Double_Window* o
		
	{
	    Fl_Double_Window* o = new Fl_Double_Window(1000, 600);
	    game_screen = o;
	    {
	        background = new Fl_Box(25, 25, 950, 550);
	        background->box(FL_DOWN_BOX);
	        background->color((Fl_Color)59);
	        background->image(background_image);
	        background->labeltype(FL_NO_LABEL);
	        background->align(Fl_Align(512));
	    } // Fl_Box* background
	    {
	        Title = new Fl_Button(450, 0, 125, 26, "Uber Casino");
	        Title->box(FL_BORDER_BOX);
	        Title->color(FL_YELLOW);
	    } // Fl_Button* Title
	    {
	        Players = new Fl_Group(25, 70, 965, 500);
	        {
	            Player_1 = new Fl_Group(30, 105, 145, 340);
	            {
	                P1_Status = new Fl_Output(75, 295, 100, 100);
	                P1_Status->box(FL_OVAL_BOX);
	                P1_Status->labeltype(FL_NO_LABEL);
	                P1_Status->value("     inactive");
	            } // Fl_Output* P1_Status
	            {
	                P1_Name = new Fl_Text_Display(90, 405, 80, 20, "Player Name:");
	                P1_Name->labeltype(FL_SHADOW_LABEL);
	                P1_Name->labelsize(8);
	                P1_Name->labelcolor((Fl_Color)3);
	                P1_Name->textsize(8);
	                P1_Name->textcolor((Fl_Color)140);
	                P1_Name->align(Fl_Align(FL_ALIGN_LEFT));
					P1NameBuff = new Fl_Text_Buffer();
	                P1_Name->buffer(P1NameBuff);
	            } // Fl_Text_Display* P1_Name
	            {
	                P1_clock = new Fl_Text_Display(115, 271, 20, 20, "Time Left:");
	                P1_clock->labeltype(FL_SHADOW_LABEL);
	                P1_clock->labelsize(8);
	                P1_clock->labelcolor((Fl_Color)3);
	                P1_clock->textsize(8);
	                P1_clock->textcolor((Fl_Color)88);
	                P1_clock->align(Fl_Align(FL_ALIGN_LEFT));
	                P1ClockBuff = new Fl_Text_Buffer();
	                P1_clock->buffer(P1ClockBuff);
	            } // Fl_Text_Display* P1_clock
	            {
	                P1C1 = new Fl_Box(30, 195, 50, 75);
	                P1C1->box(FL_UP_BOX);
	                P1C1->color(FL_BACKGROUND2_COLOR);
	                P1C1->hide();
	            } // Fl_Box* P1C1
	            {
	                P1C2 = new Fl_Box(45, 185, 50, 75);
	                P1C2->box(FL_UP_BOX);
	                P1C2->color(FL_BACKGROUND2_COLOR);
	                P1C2->hide();
	            } // Fl_Box* P1C2
	            {
	                P1C3 = new Fl_Box(60, 175, 50, 75);
	                P1C3->box(FL_UP_BOX);
	                P1C3->color(FL_BACKGROUND2_COLOR);
	                P1C3->hide();
	            } // Fl_Box* P1C3
	            {
	                P1C4 = new Fl_Box(75, 165, 50, 75);
	                P1C4->box(FL_UP_BOX);
	                P1C4->color(FL_BACKGROUND2_COLOR);
	                P1C4->hide();
	            } // Fl_Box* P1C4
	            {
	                P1C5 = new Fl_Box(90, 155, 50, 75);
	                P1C5->box(FL_UP_BOX);
	                P1C5->color(FL_BACKGROUND2_COLOR);
	                P1C5->hide();
	            } // Fl_Box* P1C5
	            {
	                P1C6 = new Fl_Box(105, 145, 50, 75);
	                P1C6->box(FL_UP_BOX);
	                P1C6->color(FL_BACKGROUND2_COLOR);
	                P1C6->hide();
	            } // Fl_Box* P1C6
	            {
	                P1C7 = new Fl_Box(120, 135, 50, 75);
	                P1C7->box(FL_UP_BOX);
	                P1C7->color(FL_BACKGROUND2_COLOR);
	                P1C7->hide();
	            } // Fl_Box* P1C7
	            {
	                P1_hand_value = new Fl_Text_Display(75, 120, 25, 25, "Hand:");
	                P1_hand_value->labeltype(FL_SHADOW_LABEL);
	                P1_hand_value->labelsize(12);
	                P1_hand_value->labelcolor((Fl_Color)3);
	                P1_hand_value->textsize(10);
	                P1_hand_value->textcolor((Fl_Color)216);
	                P1_hand_value->align(Fl_Align(FL_ALIGN_LEFT));
	                P1HandBuff = new Fl_Text_Buffer();
	                P1_hand_value->buffer(P1HandBuff);
	            } // Fl_Text_Display* P1_hand_value
	            Player_1->end();
	        } // Fl_Group* Player_1
	        {
	            Player_2 = new Fl_Group(165, 155, 140, 335);
	            {
	                P2_Status = new Fl_Output(190, 340, 100, 100);
	                P2_Status->box(FL_OVAL_BOX);
	                P2_Status->labeltype(FL_NO_LABEL);
	                P2_Status->value("     inactive");
	            } // Fl_Output* P2_Status
	            {
	                P2_Name = new Fl_Text_Display(205, 450, 80, 20, "Player Name:");
	                P2_Name->labeltype(FL_SHADOW_LABEL);
	                P2_Name->labelsize(8);
	                P2_Name->labelcolor((Fl_Color)3);
	                P2_Name->textsize(8);
	                P2_Name->textcolor((Fl_Color)140);
	                P2_Name->align(Fl_Align(FL_ALIGN_LEFT));
	                P2NameBuff = new Fl_Text_Buffer();
	                P2_Name->buffer(P2NameBuff);
	            } // Fl_Text_Display* P2_Name
	            {
	                P2_clock = new Fl_Text_Display(230, 315, 20, 20, "Time Left:");
	                P2_clock->labeltype(FL_SHADOW_LABEL);
	                P2_clock->labelsize(8);
	                P2_clock->labelcolor((Fl_Color)3);
	                P2_clock->textsize(8);
	                P2_clock->textcolor((Fl_Color)88);
	                P2_clock->align(Fl_Align(FL_ALIGN_LEFT));
	                P2ClockBuff = new Fl_Text_Buffer();
	                P2_clock->buffer(P2ClockBuff);
	            } // Fl_Text_Display* P2_clock
	            {
	                P2C1 = new Fl_Box(165, 235, 50, 75);
	                P2C1->box(FL_UP_BOX);
	                P2C1->color(FL_BACKGROUND2_COLOR);
	                P2C1->hide();
	            } // Fl_Box* P2C1
	            {
	                P2C2 = new Fl_Box(180, 225, 50, 75);
	                P2C2->box(FL_UP_BOX);
	                P2C2->color(FL_BACKGROUND2_COLOR);
	                P2C2->hide();
	            } // Fl_Box* P2C2
	            {
	                P2C3 = new Fl_Box(195, 215, 50, 75);
	                P2C3->box(FL_UP_BOX);
	                P2C3->color(FL_BACKGROUND2_COLOR);
	                P2C3->hide();
	            } // Fl_Box* P2C3
	            {
	                P2C4 = new Fl_Box(210, 205, 50, 75);
	                P2C4->box(FL_UP_BOX);
	                P2C4->color(FL_BACKGROUND2_COLOR);
	                P2C4->hide();
	            } // Fl_Box* P2C4
	            {
	                P2C5 = new Fl_Box(225, 195, 50, 75);
	                P2C5->box(FL_UP_BOX);
	                P2C5->color(FL_BACKGROUND2_COLOR);
	                P2C5->hide();
	            } // Fl_Box* P2C5
	            {
	                P2C6 = new Fl_Box(240, 185, 50, 75);
	                P2C6->box(FL_UP_BOX);
	                P2C6->color(FL_BACKGROUND2_COLOR);
	                P2C6->hide();
	            } // Fl_Box* P2C6
	            {
	                P2C7 = new Fl_Box(255, 175, 50, 75);
	                P2C7->box(FL_UP_BOX);
	                P2C7->color(FL_BACKGROUND2_COLOR);
	                P2C7->hide();
	            } // Fl_Box* P2C7
	            { P2_hand_value = new Fl_Text_Display(225, 155, 25, 25, "Hand:");
	                P2_hand_value->labeltype(FL_SHADOW_LABEL);
	                P2_hand_value->labelsize(10);
	                P2_hand_value->labelcolor((Fl_Color)3);
	                P2_hand_value->textsize(10);
	                P2_hand_value->textcolor((Fl_Color)216);
	                P2_hand_value->align(Fl_Align(FL_ALIGN_LEFT));
	                P2HandBuff = new Fl_Text_Buffer();
	                P2_hand_value->buffer(P2HandBuff);
	            } // Fl_Text_Display* P2_hand_value
	            Player_2->end();
	        } // Fl_Group* Player_2
	        {
	            Player_3 = new Fl_Group(275, 185, 140, 380);
	            {
	                P3_Status = new Fl_Output(310, 390, 100, 100);
	                P3_Status->box(FL_OVAL_BOX);
	                P3_Status->labeltype(FL_NO_LABEL);
	                P3_Status->value("     inactive");
	            } // Fl_Output* P3_Status
	            {
	                P3_Name = new Fl_Text_Display(320, 500, 80, 20, "Player Name:");
	                P3_Name->labeltype(FL_SHADOW_LABEL);
	                P3_Name->labelsize(8);
	                P3_Name->labelcolor((Fl_Color)3);
	                P3_Name->textsize(8);
	                P3_Name->textcolor((Fl_Color)140);
	                P3_Name->align(Fl_Align(FL_ALIGN_LEFT));
	                P3NameBuff = new Fl_Text_Buffer();
	                P3_Name->buffer(P3NameBuff);
	            } // Fl_Text_Display* P3_Name
	            {
	                P3_clock = new Fl_Text_Display(350, 365, 20, 20, "Time Left:");
	                P3_clock->labeltype(FL_SHADOW_LABEL);
	                P3_clock->labelsize(8);
	                P3_clock->labelcolor((Fl_Color)3);
	                P3_clock->textsize(8);
	                P3_clock->textcolor((Fl_Color)88);
	                P3_clock->align(Fl_Align(FL_ALIGN_LEFT));
	                P3ClockBuff = new Fl_Text_Buffer();
	                P3_clock->buffer(P3ClockBuff);
	            } // Fl_Text_Display* P3_clock
	            {
	                P3C1 = new Fl_Box(275, 275, 50, 75);
	                P3C1->box(FL_UP_BOX);
	                P3C1->color(FL_BACKGROUND2_COLOR);
	                P3C1->hide();
	            } // Fl_Box* P3C1
	            {
	                P3C2 = new Fl_Box(290, 265, 50, 75);
	                P3C2->box(FL_UP_BOX);
	                P3C2->color(FL_BACKGROUND2_COLOR);
	                P3C2->hide();
	            } // Fl_Box* P3C2
	            {
	                P3C3 = new Fl_Box(305, 255, 50, 75);
	                P3C3->box(FL_UP_BOX);
	                P3C3->color(FL_BACKGROUND2_COLOR);
	                P3C3->hide();
	            } // Fl_Box* P3C3
	            {
	                P3C4 = new Fl_Box(320, 245, 50, 75);
	                P3C4->box(FL_UP_BOX);
	                P3C4->color(FL_BACKGROUND2_COLOR);
	                P3C4->hide();
	            } // Fl_Box* P3C4
	            {
	                P3C5 = new Fl_Box(335, 235, 50, 75);
	                P3C5->box(FL_UP_BOX);
	                P3C5->color(FL_BACKGROUND2_COLOR);
	                P3C5->hide();
	            } // Fl_Box* P3C5
	            {
	                P3C6 = new Fl_Box(350, 225, 50, 75);
	                P3C6->box(FL_UP_BOX);
	                P3C6->color(FL_BACKGROUND2_COLOR);
	                P3C6->hide();
	            } // Fl_Box* P3C6
	            {
	                P3C7 = new Fl_Box(365, 215, 50, 75);
	                P3C7->box(FL_UP_BOX);
	                P3C7->color(FL_BACKGROUND2_COLOR);
	                P3C7->hide();
	            } // Fl_Box* P3C7
	            {
	                P3_hand_value = new Fl_Text_Display(345, 185, 25, 25, "Hand:");
	                P3_hand_value->labeltype(FL_SHADOW_LABEL);
	                P3_hand_value->labelsize(10);
	                P3_hand_value->labelcolor((Fl_Color)3);
	                P3_hand_value->textsize(10);
	                P3_hand_value->textcolor((Fl_Color)216);
	                P3_hand_value->align(Fl_Align(FL_ALIGN_LEFT));
	                P3HandBuff = new Fl_Text_Buffer();
	                P3_hand_value->buffer(P3HandBuff);
	            } // Fl_Text_Display* P3_hand_value
	            Player_3->end();
	        } // Fl_Group* Player_3
	        {
	            Player_4 = new Fl_Group(400, 205, 150, 360);
	            {
	                P4_Status = new Fl_Output(450, 415, 100, 100);
	                P4_Status->box(FL_OVAL_BOX);
	                P4_Status->labeltype(FL_NO_LABEL);
	                P4_Status->value("     inactive");
	            } // Fl_Output* P4_Status
	            {
	                P4_Name = new Fl_Text_Display(465, 525, 80, 20, "Player Name:");
	                P4_Name->labeltype(FL_SHADOW_LABEL);
	                P4_Name->labelsize(8);
	                P4_Name->labelcolor((Fl_Color)3);
	                P4_Name->textsize(8);
	                P4_Name->textcolor((Fl_Color)140);
	                P4_Name->align(Fl_Align(FL_ALIGN_LEFT));
	                P4NameBuff = new Fl_Text_Buffer();
	                P4_Name->buffer(P4NameBuff);
	            } // Fl_Text_Display* P4_Name
	            {
	                P4_clock = new Fl_Text_Display(490, 390, 20, 20, "Time Left:");
	                P4_clock->labeltype(FL_SHADOW_LABEL);
	                P4_clock->labelsize(8);
	                P4_clock->labelcolor((Fl_Color)3);
	                P4_clock->textsize(8);
	                P4_clock->textcolor((Fl_Color)88);
	                P4_clock->align(Fl_Align(FL_ALIGN_LEFT));
	                P4ClockBuff = new Fl_Text_Buffer();
	                P4_clock->buffer(P4ClockBuff);
	            } // Fl_Text_Display* P4_clock
	            {
	                P4C1 = new Fl_Box(400, 310, 50, 75);
	                P4C1->box(FL_UP_BOX);
	                P4C1->color(FL_BACKGROUND2_COLOR);
	                P4C1->hide();
	            } // Fl_Box* P4C1
	            {
	                P4C2 = new Fl_Box(415, 300, 50, 75);
	                P4C2->box(FL_UP_BOX);
	                P4C2->color(FL_BACKGROUND2_COLOR);
	                P4C2->hide();
	            } // Fl_Box* P4C2
	            {
	                P4C3 = new Fl_Box(430, 290, 50, 75);
	                P4C3->box(FL_UP_BOX);
	                P4C3->color(FL_BACKGROUND2_COLOR);
	                P4C3->hide();
	            } // Fl_Box* P4C3
	            {
	                P4C4 = new Fl_Box(445, 280, 50, 75);
	                P4C4->box(FL_UP_BOX);
	                P4C4->color(FL_BACKGROUND2_COLOR);
	                P4C4->hide();
	            } // Fl_Box* P4C4
	            {
	                P4C5 = new Fl_Box(460, 270, 50, 75);
	                P4C5->box(FL_UP_BOX);
	                P4C5->color(FL_BACKGROUND2_COLOR);
	                P4C5->hide();
	            } // Fl_Box* P4C5
	            {
	                P4C6 = new Fl_Box(475, 260, 50, 75);
	                P4C6->box(FL_UP_BOX);
	                P4C6->color(FL_BACKGROUND2_COLOR);
	                P4C6->hide();
	            } // Fl_Box* P4C6
	            {
	                P4C7 = new Fl_Box(490, 250, 50, 75);
	                P4C7->box(FL_UP_BOX);
	                P4C7->color(FL_BACKGROUND2_COLOR);
	                P4C7->hide();
	            } // Fl_Box* P4C7
	            {
	                P4_hand_value = new Fl_Text_Display(485, 205, 25, 25, "Hand:");
	                P4_hand_value->labeltype(FL_SHADOW_LABEL);
	                P4_hand_value->labelsize(10);
	                P4_hand_value->labelcolor((Fl_Color)3);
	                P4_hand_value->textsize(10);
	                P4_hand_value->textcolor((Fl_Color)216);
	                P4_hand_value->align(Fl_Align(FL_ALIGN_LEFT));
	                P4HandBuff = new Fl_Text_Buffer();
	                P4_hand_value->buffer(P4HandBuff);
	            } // Fl_Text_Display* P4_hand_value
	            Player_4->end();
	        } // Fl_Group* Player_4
	        {
	            Player_5 = new Fl_Group(545, 195, 145, 345);
	            {
	                P5_Status = new Fl_Output(590, 390, 100, 100);
	                P5_Status->box(FL_OVAL_BOX);
	                P5_Status->labeltype(FL_NO_LABEL);
	                P5_Status->value("     inactive");
	            } // Fl_Output* P5_Status
	            {
	                P5_Name = new Fl_Text_Display(605, 500, 80, 20, "Player Name:");
	                P5_Name->labeltype(FL_SHADOW_LABEL);
	                P5_Name->labelsize(8);
	                P5_Name->labelcolor((Fl_Color)3);
	                P5_Name->textsize(8);
	                P5_Name->textcolor((Fl_Color)140);
	                P5_Name->align(Fl_Align(FL_ALIGN_LEFT));
	                P5NameBuff = new Fl_Text_Buffer();
	                P5_Name->buffer(P5NameBuff);
	            } // Fl_Text_Display* P5_Name
	            {
	                P5_clock = new Fl_Text_Display(630, 365, 20, 20, "Time Left:");
	                P5_clock->labeltype(FL_SHADOW_LABEL);
	                P5_clock->labelsize(8);
	                P5_clock->labelcolor((Fl_Color)3);
	                P5_clock->textsize(8);
	                P5_clock->textcolor((Fl_Color)88);
	                P5_clock->align(Fl_Align(FL_ALIGN_LEFT));
	                P5ClockBuff = new Fl_Text_Buffer();
	                P5_clock->buffer(P5ClockBuff);
	            } // Fl_Text_Display* P5_clock
	            {
	                P5C1 = new Fl_Box(545, 285, 50, 75);
	                P5C1->box(FL_UP_BOX);
	                P5C1->color(FL_BACKGROUND2_COLOR);
	                P5C1->hide();
	            } // Fl_Box* P5C1
	            {
	                P5C2 = new Fl_Box(560, 275, 50, 75);
	                P5C2->box(FL_UP_BOX);
	                P5C2->color(FL_BACKGROUND2_COLOR);
	                P5C2->hide();
	            } // Fl_Box* P5C2
	            {
	                P5C3 = new Fl_Box(575, 265, 50, 75);
	                P5C3->box(FL_UP_BOX);
	                P5C3->color(FL_BACKGROUND2_COLOR);
	                P5C3->hide();
	            } // Fl_Box* P5C3
	            {
	                P5C4 = new Fl_Box(590, 255, 50, 75);
	                P5C4->box(FL_UP_BOX);
	                P5C4->color(FL_BACKGROUND2_COLOR);
	                P5C4->hide();
	            } // Fl_Box* P5C4
	            {
	                P5C5 = new Fl_Box(605, 245, 50, 75);
	                P5C5->box(FL_UP_BOX);
	                P5C5->color(FL_BACKGROUND2_COLOR);
	                P5C5->hide();
	            } // Fl_Box* P5C5
	            {
	                P5C6 = new Fl_Box(620, 235, 50, 75);
	                P5C6->box(FL_UP_BOX);
	                P5C6->color(FL_BACKGROUND2_COLOR);
	                P5C6->hide();
	            } // Fl_Box* P5C6
	            {
	                P5C7 = new Fl_Box(635, 225, 50, 75);
	                P5C7->box(FL_UP_BOX);
	                P5C7->color(FL_BACKGROUND2_COLOR);
	                P5C7->hide();
	            } // Fl_Box* P5C7
	            {
	                P5_hand_value = new Fl_Text_Display(625, 195, 25, 25, "Hand:");
	                P5_hand_value->labeltype(FL_SHADOW_LABEL);
	                P5_hand_value->labelsize(10);
	                P5_hand_value->labelcolor((Fl_Color)3);
	                P5_hand_value->textsize(10);
	                P5_hand_value->textcolor((Fl_Color)216);
	                P5_hand_value->align(Fl_Align(FL_ALIGN_LEFT));
	                P5HandBuff = new Fl_Text_Buffer();
	                P5_hand_value->buffer(P5HandBuff);
	            } // Fl_Text_Display* P5_hand_value
	            Player_5->end();
	        } // Fl_Group* Player_5
	        {
	            Player_6 = new Fl_Group(685, 150, 150, 340);
	            { P6_Status = new Fl_Output(735, 340, 100, 100);
	                P6_Status->box(FL_OVAL_BOX);
	                P6_Status->labeltype(FL_NO_LABEL);
	                P6_Status->value("     inactive");
	            } // Fl_Output* P6_Status
	            {
	                P6_Name = new Fl_Text_Display(750, 450, 80, 20, "Player Name:");
	                P6_Name->labeltype(FL_SHADOW_LABEL);
	                P6_Name->labelsize(8);
	                P6_Name->labelcolor((Fl_Color)3);
	                P6_Name->textsize(8);
	                P6_Name->textcolor((Fl_Color)140);
	                P6_Name->align(Fl_Align(FL_ALIGN_LEFT));
	                P6NameBuff = new Fl_Text_Buffer();
	                P6_Name->buffer(P6NameBuff);
	            } // Fl_Text_Display* P6_Name
	            {
	                P6_clock = new Fl_Text_Display(773, 315, 20, 20, "Time Left:");
	                P6_clock->labeltype(FL_SHADOW_LABEL);
	                P6_clock->labelsize(8);
	                P6_clock->labelcolor((Fl_Color)3);
	                P6_clock->textsize(8);
	                P6_clock->textcolor((Fl_Color)88);
	                P6_clock->align(Fl_Align(FL_ALIGN_LEFT));
	                P6ClockBuff = new Fl_Text_Buffer();
	                P6_clock->buffer(P6ClockBuff);
	            } // Fl_Text_Display* P6_clock
	            {
	                P6C1 = new Fl_Box(687, 240, 50, 75);
	                P6C1->box(FL_UP_BOX);
	                P6C1->color(FL_BACKGROUND2_COLOR);
	                P6C1->hide();
	            } // Fl_Box* P6C1
	            {
	                P6C2 = new Fl_Box(702, 230, 50, 75);
	                P6C2->box(FL_UP_BOX);
	                P6C2->color(FL_BACKGROUND2_COLOR);
	                P6C2->hide();
	            } // Fl_Box* P6C2
	            {
	                P6C3 = new Fl_Box(717, 220, 50, 75);
	                P6C3->box(FL_UP_BOX);
	                P6C3->color(FL_BACKGROUND2_COLOR);
	                P6C3->hide();
	            } // Fl_Box* P6C3
	            {
	                P6C4 = new Fl_Box(732, 210, 50, 75);
	                P6C4->box(FL_UP_BOX);
	                P6C4->color(FL_BACKGROUND2_COLOR);
	                P6C4->hide();
	            } // Fl_Box* P6C4
	            {
	                P6C5 = new Fl_Box(747, 200, 50, 75);
	                P6C5->box(FL_UP_BOX);
	                P6C5->color(FL_BACKGROUND2_COLOR);
	                P6C5->hide();
	            } // Fl_Box* P6C5
	            {
	                P6C6 = new Fl_Box(762, 190, 50, 75);
	                P6C6->box(FL_UP_BOX);
	                P6C6->color(FL_BACKGROUND2_COLOR);
	                P6C6->hide();
	            } // Fl_Box* P6C6
	            {
	                P6C7 = new Fl_Box(777, 180, 50, 75);
	                P6C7->box(FL_UP_BOX);
	                P6C7->color(FL_BACKGROUND2_COLOR);
	                P6C7->hide();
	            } // Fl_Box* P6C7
	            {
	                P6_hand_value = new Fl_Text_Display(765, 150, 25, 25, "Hand:");
	                P6_hand_value->labeltype(FL_SHADOW_LABEL);
	                P6_hand_value->labelsize(10);
	                P6_hand_value->labelcolor((Fl_Color)3);
	                P6_hand_value->textsize(10);
	                P6_hand_value->textcolor((Fl_Color)216);
	                P6_hand_value->align(Fl_Align(FL_ALIGN_LEFT));
	                P6HandBuff = new Fl_Text_Buffer();
	                P6_hand_value->buffer(P6HandBuff);
	            } // Fl_Text_Display* P6_hand_value
	            Player_6->end();
	        } // Fl_Group* Player_6
	        {
	            Player_7 = new Fl_Group(830, 105, 140, 340);
	            {
	                P7_Status = new Fl_Output(867, 295, 100, 100);
	                P7_Status->box(FL_OVAL_BOX);
	                P7_Status->labeltype(FL_NO_LABEL);
	                P7_Status->value("     inactive");
	            } // Fl_Output* P7_Status
	            {
	                P7_Name = new Fl_Text_Display(895, 405, 80, 20, "Player Name:");
	                P7_Name->labeltype(FL_SHADOW_LABEL);
	                P7_Name->labelsize(8);
	                P7_Name->labelcolor((Fl_Color)3);
	                P7_Name->textsize(8);
	                P7_Name->textcolor((Fl_Color)140);
	                P7_Name->align(Fl_Align(FL_ALIGN_LEFT));
	                P7NameBuff = new Fl_Text_Buffer();
	                P7_Name->buffer(P7NameBuff);
	            } // Fl_Text_Display* P7_Name
	            {
	                P7_clock = new Fl_Text_Display(905, 270, 20, 20, "Time Left:");
	                P7_clock->labeltype(FL_SHADOW_LABEL);
	                P7_clock->labelsize(8);
	                P7_clock->labelcolor((Fl_Color)3);
	                P7_clock->textsize(8);
	                P7_clock->textcolor((Fl_Color)88);
	                P7_clock->align(Fl_Align(FL_ALIGN_LEFT));
	                P7ClockBuff = new Fl_Text_Buffer();
	                P7_clock->buffer(P7ClockBuff);
	            } // Fl_Text_Display* P7_clock
	            {
	                P7C1 = new Fl_Box(830, 195, 50, 75);
	                P7C1->box(FL_UP_BOX);
	                P7C1->color(FL_BACKGROUND2_COLOR);
	                P7C1->hide();
	            } // Fl_Box* P7C1
	            {
	                P7C2 = new Fl_Box(845, 185, 50, 75);
	                P7C2->box(FL_UP_BOX);
	                P7C2->color(FL_BACKGROUND2_COLOR);
	                P7C2->hide();
	            } // Fl_Box* P7C2
	            {
	                P7C3 = new Fl_Box(860, 175, 50, 75);
	                P7C3->box(FL_UP_BOX);
	                P7C3->color(FL_BACKGROUND2_COLOR);
	                P7C3->hide();
	            } // Fl_Box* P7C3
	            {
	                P7C4 = new Fl_Box(875, 165, 50, 75);
	                P7C4->box(FL_UP_BOX);
	                P7C4->color(FL_BACKGROUND2_COLOR);
	                P7C4->hide();
	            } // Fl_Box* P7C4
	            {
	                P7C5 = new Fl_Box(890, 155, 50, 75);
	                P7C5->box(FL_UP_BOX);
	                P7C5->color(FL_BACKGROUND2_COLOR);
	                P7C5->hide();
	            } // Fl_Box* P7C5
	            {
	                P7C6 = new Fl_Box(905, 145, 50, 75);
	                P7C6->box(FL_UP_BOX);
	                P7C6->color(FL_BACKGROUND2_COLOR);
	                P7C6->hide();
	            } // Fl_Box* P7C6
	            {
	                P7C7 = new Fl_Box(920, 135, 50, 75);
	                P7C7->box(FL_UP_BOX);
	                P7C7->color(FL_BACKGROUND2_COLOR);
	                P7C7->hide();
	            } // Fl_Box* P7C7
	            {
	                P7_hand_value = new Fl_Text_Display(910, 105, 25, 25, "Hand:");
	                P7_hand_value->labeltype(FL_SHADOW_LABEL);
	                P7_hand_value->labelsize(10);
	                P7_hand_value->labelcolor((Fl_Color)3);
	                P7_hand_value->textsize(10);
	                P7_hand_value->textcolor((Fl_Color)216);
	                P7_hand_value->align(Fl_Align(FL_ALIGN_LEFT));
	                P7HandBuff = new Fl_Text_Buffer();
	                P7_hand_value->buffer(P7HandBuff);
	            } // Fl_Text_Display* P7_hand_value
	            Player_7->end();
	        } // Fl_Group* Player_7
	        Players->end();
	    } // Fl_Group* Players
	    {
	        Fl_Button* o = new Fl_Button(40, 540, 100, 25, "End Game");
	        o->color((Fl_Color)1);
	        o->callback( (Fl_Callback *)end_game );
	        o->hide();
	        EndGame = o;
	    } // Fl_Button* o
	    {
	        Fl_Button* o = new Fl_Button(40, 540, 100, 25, "Start Game");
	        o->color(FL_GREEN);
	        o->selection_color(FL_BLACK);
	        o->callback( (Fl_Callback *)start_game );
	        o->hide();
	        StartButton = o;
	    } // Fl_Button* o
	    {
	        Fl_Button* o = new Fl_Button(725, 540, 125, 25, "Deal Next Hand");
	        o->color(FL_CYAN);
	        o->selection_color(FL_BLACK);
	        o->callback( (Fl_Callback *)next_hand );
	        o->hide();
	        NextHand = o;
	    } // Fl_Button* o
	    {
	        Fl_Button* o = new Fl_Button(860, 540, 100, 25, "Deal Auto");
	        o->color(FL_MAGENTA);
	        o->selection_color(FL_BLACK);
	        o->callback( (Fl_Callback *)deal_auto );
	        DealAuto = o;
	    } // Fl_Button* o
	    {
	        Fl_Text_Display* o = new Fl_Text_Display(80, 28, 50, 20, "Game ID:");
	        o->labeltype(FL_SHADOW_LABEL);
	        o->labelsize(10);
	        o->labelcolor(FL_BACKGROUND2_COLOR);
	        o->textsize(10);
	        o->textcolor(FL_BACKGROUND2_COLOR);
	        o->align(Fl_Align(FL_ALIGN_LEFT));
	        o->hide();
	    } // Fl_Text_Display* o
	    {
	        statusDisplay = new Fl_Text_Display(80, 50, 100, 20, "Status:");
	        statusDisplay->labeltype(FL_SHADOW_LABEL);
	        statusDisplay->labelsize(10);
	        statusDisplay->labelcolor(FL_BACKGROUND2_COLOR);
	        statusDisplay->textsize(10);
	        statusDisplay->align(Fl_Align(FL_ALIGN_LEFT));
	        statusBuff = new Fl_Text_Buffer();
	        statusDisplay->buffer(statusBuff);
	        statusBuff->text( to_string( game->G_pub.gstate ).c_str() );
	    } // Fl_Text_Display* o
	    {
	        playersDisplay = new Fl_Text_Display(80, 70, 25, 20, "Players:");
	        playersDisplay->labeltype(FL_SHADOW_LABEL);
	        playersDisplay->labelsize(10);
	        playersDisplay->labelcolor(FL_BACKGROUND2_COLOR);
	        playersDisplay->textsize(10);
	        playersDisplay->align(Fl_Align(FL_ALIGN_LEFT));
	        playersBuff = new Fl_Text_Buffer();
	        playersDisplay->buffer(playersBuff);
	        playersBuff->text("0");
	    } // Fl_Text_Display* o
	    {
	        shoeTypeDisplay = new Fl_Text_Display(920, 30, 50, 20, "Shoe Type:");
	        shoeTypeDisplay->labeltype(FL_SHADOW_LABEL);
	        shoeTypeDisplay->labelsize(10);
	        shoeTypeDisplay->labelcolor(FL_BACKGROUND2_COLOR);
	        shoeTypeDisplay->textsize(10);
	        shoeTypeDisplay->align(Fl_Align(FL_ALIGN_LEFT));
	        shoeTypeBuff = new Fl_Text_Buffer();
	        shoeTypeDisplay->buffer(shoeTypeBuff);
	    } // Fl_Text_Display* o
	    {
	        countDisplay = new Fl_Text_Display(920, 50, 50, 20, "Table Count:");
	        countDisplay->labeltype(FL_SHADOW_LABEL);
	        countDisplay->labelsize(10);
	        countDisplay->labelcolor(FL_BACKGROUND2_COLOR);
	        countDisplay->textsize(10);
	        countDisplay->align(Fl_Align(FL_ALIGN_LEFT));
	        countBuff = new Fl_Text_Buffer();
	        countDisplay->buffer(countBuff);
	        countBuff->text("0");
	    } // Fl_Text_Display* o
	    {
	        Fl_Text_Display* o = new Fl_Text_Display(920, 70, 50, 20, "Table Min:");
	        o->labeltype(FL_SHADOW_LABEL);
	        o->labelsize(10);
	        o->labelcolor(FL_BACKGROUND2_COLOR);
	        o->textsize(10);
	        o->align(Fl_Align(FL_ALIGN_LEFT));
	        Fl_Text_Buffer* b = new Fl_Text_Buffer();
	        o->buffer(b);
	        b->text("$5.00");
	    } // Fl_Text_Display* o
	    {
	        GUI_Dealer = new Fl_Group(385, 27, 315, 108);
	        {
	            duid = new Fl_Text_Display(525, 27, 75, 25, "Dealer Name:");
	            duid->labelcolor((Fl_Color)3);
	            duid->align(Fl_Align(FL_ALIGN_LEFT));
	            duidBuffer = new Fl_Text_Buffer();
	            duid->buffer(duidBuffer);
	            duidBuffer->text( ( (string)game->D_pub.name ).c_str() );
	        } // Fl_Text_Display* o
	        {
	            DC1 = new Fl_Box(460, 60, 50, 75);
	            DC1->box(FL_UP_BOX);
	            DC1->color(FL_BACKGROUND2_COLOR);
	            DC1->hide();
	        } // Fl_Box* DC1
	        {
	            DC2 = new Fl_Box(515, 60, 50, 75);
	            DC2->box(FL_UP_BOX);
	            DC2->color(FL_BACKGROUND2_COLOR);
	            DC2->hide();
	        } // Fl_Box* DC2
	        {
	            DC3 = new Fl_Box(570, 60, 50, 75);
	            DC3->box(FL_UP_BOX);
	            DC3->color(FL_BACKGROUND2_COLOR);
	            DC3->hide();
	        } // Fl_Box* DC3
	        {
	            DC4 = new Fl_Box(590, 60, 50, 75);
	            DC4->box(FL_UP_BOX);
	            DC4->color(FL_BACKGROUND2_COLOR);
	            DC4->hide();
	        } // Fl_Box* DC4
	        {
	            DC5 = new Fl_Box(610, 60, 50, 75);
	            DC5->box(FL_UP_BOX);
	            DC5->color(FL_BACKGROUND2_COLOR);
	            DC5->hide();
	        } // Fl_Box* DC5
	        {
	            DC6 = new Fl_Box(630, 60, 50, 75);
	            DC6->box(FL_UP_BOX);
	            DC6->color(FL_BACKGROUND2_COLOR);
	            DC6->hide();
	        } // Fl_Box* DC6
	        {
	            DC7 = new Fl_Box(650, 60, 50, 75);
	            DC7->box(FL_UP_BOX);
	            DC7->color(FL_BACKGROUND2_COLOR);
	            DC7->hide();
	        } // Fl_Box* DC7
	        {
	            DHandDisplay = new Fl_Text_Display(410, 105, 25, 25, "Hand:");
	            DHandDisplay->labeltype(FL_SHADOW_LABEL);
	            DHandDisplay->labelsize(10);
	            DHandDisplay->labelcolor((Fl_Color)3);
	            DHandDisplay->textsize(10);
	            DHandDisplay->textcolor((Fl_Color)216);
	            DHandDisplay->align(Fl_Align(FL_ALIGN_LEFT));
	            DHandBuff = new Fl_Text_Buffer();
	            DHandDisplay->buffer(DHandBuff);
	        } // Fl_Text_Display* o
	        GUI_Dealer->end();
	    } // Fl_Group* Dealer
	    {
	        Suggestion_box = new Fl_Text_Display(400, 145, 250, 30);
	        suggestionBuff = new Fl_Text_Buffer();
	        Suggestion_box->buffer(suggestionBuff);
	    } // Fl_Text_Display* Suggestion_box
	    {
	        shoe_bar = new Fl_Progress(615, 33, 220, 20, "Cards Remaining");
	        shoe_bar->selection_color(FL_GREEN);
	        shoe_bar->maximum(416.00);
	        shoe_bar->minimum(0.00);
	        shoe_bar->value(416.00);
	        shoe_bar->hide();
	    } // Fl_Progress* shoe_bar
	    {
	    	testPopUp = new Fl_Double_Window(315, 225, 400, 100, "Test Selection");
	    	testPopUp->begin();
				testSelector = new Fl_Choice(100, 10, 290, 30, "Which Test: ");
				testSelector->add("Test Suite");
				testSelector->add("Test Scenario 1");
				testSelector->add("Test Scenario 2");
				testSelector->add("Test Scenario 3");
				testSelector->add("Test Scenario 4");
				testSelector->add("Test Scenario 5");
				testSelector->add("Test Scenario 6");
				testSelector->add("Test Scenario 7");
				testSelector->add("Test Scenario 8");
				testSelector->add("Test Scenario 9");
				testSelector->add("Test Scenario 10");
				testButton = new Fl_Button(365, 65, 25, 25, "OK");
				testButton->callback((Fl_Callback*)test_selection);
			testPopUp->end();
	    	testPopUp->hide();
	    }
	    o->end();
	    o->resizable(o);
	} // Fl_Double_Window* o
		
	open_screen->show();
	Fl::lock();
        
    return Fl::run();
}


