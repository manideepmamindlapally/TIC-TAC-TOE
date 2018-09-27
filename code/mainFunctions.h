#include <iostream>
#include <string>

#include "mainClasses.cc"

void initialPrompt(std::string Players[]);
void gameInput(std::string Players[], GameBoard &Grid, int turn);
int checkGame(std::string Players[], GameBoard &Grid);
int exitPrompt();
int gameFlow(std::string Players[], GameBoard Grid);


//prompts the players and enters their names
void initialPrompt(std::string Players[])
{
	std::cout << "=================================================\n";
	std::cout << "          Welcome! You are now about to play \n              THE TIC TAC TOE GAME!   \n";
	std::cout << "-------------------------------------------------\n";
	std::cin.clear();	
	std::cout << "Player X: ";
	getline(std::cin, Players[0]);
	std::cin.clear();
	std::cout << "Player O: ";
	getline(std::cin, Players[1]);
}

//sets the players choice in the Grid GameBoard
void gameInput(std::string Players[], GameBoard &Grid, int turn)
{
	char entries[2] = {'X', 'O'};
	int row, column;
	std::cout << "  " << Players[turn] << ", where would you place your " << entries[turn] << "?\n";
	std::cin.clear();
	std::cout << "row: ";
	std::cin.clear();
	std::cin >> row;
	std::cout << "column: ";
	std::cin >> column;
	//Recursively take gameInput if the box is already taken
	if(Grid.setValue(row-1, column-1, entries[turn]) == 0)
	{
		std::cout << "The box is already filled! Choose another box\n";
		gameInput(Players, Grid, turn);
	}
}

//Check if the game is already over or not
// return 1 if over, 0 is not over
int checkGame(std::string Players[], GameBoard &Grid)
{
	// From GameBoard class, know the winner from the checkGameOver return value
	switch(Grid.checkGameOver())
	{
		case 0:		return 0;
		case 1: 	std::cout << "Congratulations! " << Players[0] << ", You Won\n";
					break;
		case 2:		std::cout << "Congratulations! " << Players[1] << ", You Won\n";
					break;
		case 3: 	std::cout << "Game Over! It ends in a draw\n";
	}
	return 1;
}

//The exit prompt is
// presss 1 to play again
//	0 to exit
int exitPrompt()
{
	int prompt;
	std::cin.clear();
	std::cout << "Would you like to play again?(Press 1 to play, 0 to exit): ";
	std::cin >> prompt;
	return prompt; 
}

//your game runs here
int gameFlow(std::string Players[], GameBoard Grid)
{
	initialPrompt(Players);
	//loop for different rounds
	for(int round=0; round<=SIZE*SIZE+1; round++)
	{
		gameInput(Players, Grid, round%2);
		Grid.printGrid();
		if(checkGame(Players, Grid))
			break;
	}
	return exitPrompt();
}