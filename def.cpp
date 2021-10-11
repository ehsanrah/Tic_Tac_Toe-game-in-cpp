#include <iostream>
#include "dec.h"
using namespace std;
string board[9] = {" "," "," "," "," "," "," "," "," "};
int player = 1;
int position = 0;

void introduction()
{
	cout<<"press [Enter] to begin: ";
	getchar(); //halts the screen;
	cout<<"\n";
	cout<<"\n";
	cout<<"***********\n";
	cout<<"Tic-Tac-Toe\n";
	cout<<"***********\n";
	
	cout<<"Player 1) X\n";
	cout<<"Player 2) O\n";
	
	cout<<"     |     |     \n";
	cout<<"  1  |  2  |  3  \n";
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  4  |  5  |  6  \n";
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  7  |  8  |  9  \n";
	cout<<"     |     |     \n\n";
	
}

bool is_winner() 
{
	bool win = false;	
	for (int i =0;i <3; i++)
	{
		if (board[3*i] == board[3*i+1] && board[3*i+1] == board[3*i+2] && board[3*i] != " ")
		{
			win =true;
		}
	}
	
	// checking the columns
	for (int i =0;i <3; i++)
	{
		if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != " ")
		{
			win =true;
		}
	}
	
	// checking the diagonals

	if ((board[0] == board[4]  && board[4] == board[8] && board[0] !=" ") || (board[2] == board[4]  && board[4] == board[6] && board[2] !=" "))
	{
		win =true;
	}
	return win;
}

bool filled_up()
{
	bool filled = true;
	for (int i=0; i<9; i++)
	{
		if(board[i]==" ")
		{
			filled = false;
		}
	}
	return filled;
}

void draw()
{
	cout<<"     |     |     \n";
	cout<<"  "<<board[0]<<"  |"<<"  "<<board[1]<<"  |"<<"  "<<board[2]<<"  "<<"\n";
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  "<<board[3]<<"  |"<<"  "<<board[4]<<"  |"<<"  "<<board[5]<<"  "<<"\n";
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  "<<board[6]<<"  |"<<"  "<<board[7]<<"  |"<<"  "<<board[8]<<"  "<<"\n";
	cout<<"     |     |     \n\n";
}

void set_position()
{
	cout<<"player "<<player<<"'s (Enter: (1:9)): ";
	cin>>position;
	cout<<endl;
	while (board[position -1] != " "){
    cout<<"Oops, that position is already filled\nTry again\n";
    cout << "Player " << player << "'s Turn (Enter 1-9): ";
    cin>>position;
    cout<<"\n";
	}
	
}

void board_update() 
{
	if (player % 2 == 1)
		board[position - 1] = "X";
	else
		board[position - 1] = "O";
}

void change_player() 
{
	if (player == 1)
		player++;
	else
		player--;
}

void take_turn()
{
	while(!is_winner() && !filled_up())
	{
		set_position();
		board_update();
		change_player();
		draw();
	}
}

void end_game()
{
	if(is_winner())
	{
		change_player();
		cout<<"player "<<player<<" is the winner"<<endl;
	}
	else if(filled_up())
	{
		cout<<"The game is tied"<<endl;		
	}

}
