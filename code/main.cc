#include "mainFunctions.h"

int main()
{
	while(1)
	{
		GameBoard TicTacToe;
		std::string Players[2];
		if(gameFlow(Players, TicTacToe) == 1)	continue;
		break;
	}
	return 0;
}