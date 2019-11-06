#include <iostream>
#include <string>
#include <vector>
#include "test_suite.h"

using namespace std;

int t05( bool *passed )
{
	int failCount = 0;
	
	for ( int i = 0; i < 36; i++ )
	{
		for ( int j = 0; j < 10; j++ )
		{
			Player p;
			strcpy( p.name, "test" );
			player_instance pi(p);
			pi.player_num = 1;
			
			card_t card1;
			card1.suite = hearts;
			card_t card2;
			card2.suite = hearts;
			
			if ( i < 9 )
			{
				card1.card = (card_kind)( i + 1 );
				card2.card = (card_kind)( i + 1 );
			}
			else if ( i < 19 )
			{
				card1.card = (card_kind)( 0 );
				card2.card = (card_kind)( i - 9 );
			}
			else
			{
				card1.card = (card_kind)( i - 17 );
				card2.card = (card_kind)( 1 );
			}
			
			pi.add_card( card1 );
			pi.add_card( card2 );
			string result = pi.suggest_move( j + 2 );
			
			int move;
			
			if ( i < 2 || i == 5 )
			{
				if ( j < 6 )
					move = 3;
				else
					move = 0;
			}
			else if ( i == 2 )
			{
				if ( j == 3 || j == 4 )
					move = 3;
				else
					move = 0;
			}
			else if ( i == 24 || i == 3 )
			{
				if ( j < 8 )
					move = 2;
				else
					move = 0;
			}
			else if ( i == 4 )
			{
				if ( j < 5 )
					move = 3;
				else
					move = 0;
			}
			else if ( i == 6 || i == 9 )
			{
				move = 3;
			}
			else if ( i == 7 )
			{
				if ( j == 5 || j > 7 )
					move = 1;
				else
					move = 3;
			}
			else if ( i == 8 || ( i > 15 && i < 19 ) )
			{
				move = 1;
			}
			else if ( i == 10 || i == 11 )
			{
				if ( j == 3 || j == 4 )
					move = 2;
				else
					move = 0;
			}
			else if ( i == 12 || i == 13 )
			{
				if ( j > 1 && j < 5 )
					move = 2;
				else
					move = 0;
			}
			else if ( i == 14 )
			{
				if ( j > 0 && j < 5 )
					move = 2;
				else
					move = 0;
			}
			else if ( i == 15 )
			{
				if ( j > 0 && j < 5 )
					move = 2;
				else if ( j < 7 )
					move = 1;
				else
					move = 0;
			}
			else if ( i < 23 )
			{
				move = 0;
			}
			else if ( i == 23 )
			{
				if ( j > 0 && j < 5 )
					move = 2;
				else
					move = 0;
			}
			else if ( i == 25 )
			{
				if ( j < 9 )
					move = 2;
				else
					move = 0;
			}
			else if ( i == 26 )
			{
				if ( j > 1 && j < 5 )
					move = 1;
				else
					move = 0;
			}
			else if ( i > 26 && i < 31 )
			{
				if ( j < 5 )
					move = 1;
				else
					move = 0;
			}
			else
			{
				move = 1;
			}
			
			if ( move == 0 )
			{
				if ( result != "Player 2 should hit" )
				{
					cout << "t05 test failure " << ++failCount << ":\n\tExpected result: Player 2 should hit\n\tReturned result: " << result << endl << "\ti: " << i << "\tj: " << j << endl;
					*passed = false;
				}
			}
			else if ( move == 1 )
			{
				if ( result != "Player 2 should stand" )
				{
					cout << "t05 test failure " << ++failCount << ":\n\tExpected result: Player 2 should stand\n\tReturned result: " << result << endl << "\ti: " << i << "\tj: " << j << endl;
					*passed = false;
				}
			}
			else if ( move == 2 )
			{
				if ( result != "Player 2 should double down" )
				{
					cout << "t05 test failure " << ++failCount << ":\n\tExpected result: Player 2 should double\n\tReturned result: " << result << endl << "\ti: " << i << "\tj: " << j << endl;
					*passed = false;
				}
			}
			else if ( move == 3 )
			{
				if ( result != "Player 2 should split" )
				{
					cout << "t05 test failure " << ++failCount << ":\n\tExpected result: Player 2 should split\n\tReturned result: " << result << endl << "\ti: " << i << "\tj: " << j << endl;
					*passed = false;
				}
			}
			else
			{
				cout << "move variable never set! This should not be able to happen!" << cout;
			}
		}
	}
	
	return failCount;
}

int t07(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t18(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t19(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t21(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t22(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t23(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t29(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t30(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t31(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t32(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t33(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t34(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t35(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t36(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t37(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t38(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t39(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t40(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

int t41(bool *passed)
{
	int failCount = 0;
	
	return failCount;
}

void run_tests()
{
	bool passed = true;
	vector<int> testFails;
	string tNames[] = {"t05", "t07", "t018", "t19", "t21", "t22", "t23", "t29", "t30", "t31", "t32", "t33", "t34", "t35", "t36", "t37", "t38", "t39", "t40", "t41"};
	
	//test calls
	testFails.push_back( t05(&passed) );
	testFails.push_back( t07(&passed) );
	testFails.push_back( t18(&passed) );
	testFails.push_back( t19(&passed) );
	//t20(&passed); TODO maybe do this here
	testFails.push_back( t21(&passed) );
	testFails.push_back( t22(&passed) );
	testFails.push_back( t23(&passed) );
	testFails.push_back( t29(&passed) );
	testFails.push_back( t30(&passed) );
	testFails.push_back( t31(&passed) );
	testFails.push_back( t32(&passed) );
	testFails.push_back( t33(&passed) );
	testFails.push_back( t34(&passed) );
	testFails.push_back( t35(&passed) );
	testFails.push_back( t36(&passed) );
	testFails.push_back( t37(&passed) );
	testFails.push_back( t38(&passed) );
	testFails.push_back( t39(&passed) );
	testFails.push_back( t40(&passed) );
	testFails.push_back( t41(&passed) );
	
	if ( passed )
	{
		cout << "Test suite passed!" << endl;
	}
	else
	{
		cout << endl << "********Test Summary********" << endl << endl;
		
		for (int i = 0; i < 20; i++)
		{
			if (testFails[i] > 0)
			{
				cout << tNames[i] << " failures: " << testFails[i] << endl;
			}
		}
	}
	sleep(1);
	return;
}
