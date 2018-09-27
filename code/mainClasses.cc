const int SIZE = 4;

//The class GameBoard
class GameBoard
{
	private:
		char gridValue[SIZE][SIZE];
	public:
		GameBoard();
		int setValue(int row, int column, char value);
		char getValue(int row, int column);         
		int checkRow();
		int checkColumn();
		int checkPrincipalDiagonal();
		int checkNonPrincipalDiagonal();
		int checkGridFilled();
		int checkWinner();
		int checkGameOver();
		void printGrid();
		~GameBoard();
};

// set all the positions on the board
GameBoard::GameBoard()
{
	for (int row = 0; row < SIZE; row++)
		for(int column=0; column<SIZE; column++)
				gridValue[row][column] = '-';
}

// enter the value into the grid
int GameBoard::setValue(int row, int column, char value)
{
	//set the value only if the grid box is not occupied
	if(gridValue[row][column] != '-')
		return 0;
	gridValue[row][column] = value;
	return 1;
}

// get the value on the grid
// only for debugging - not used in the program at all
char GameBoard::getValue(int row, int column)
{
	return gridValue[row][column];
}

//check whether a row is won
int GameBoard::checkRow()
{	
	int row, column, flag;
	for(row=0; row<SIZE; row++)
	{	
		flag = 1;
		//check all colums of a given row
		for(column=1; column<SIZE; column++)
		{
			if(gridValue[row][column-1] != gridValue[row][column] || gridValue[row][column] == '-')
			{
				flag=0;
				break;
			}	
		}
		// if the rowth row is won
		if(flag == 1)
		{
			switch(gridValue[row][column-1])
			{
				case 'X':	return 1;
				case 'O':	return 2;
			}
		}
	}
	return 0;
}

//check whether a column is won
int GameBoard::checkColumn()
{	
	int row, column, flag;
	for(column=0; column<SIZE; column++)
	{
		flag = 1;
		//check all rows of a given column
		for(row=1; row<SIZE; row++)
		{
			if(gridValue[row-1][column] != gridValue[row][column] || gridValue[row][column] == '-')
			{
				flag=0;
				break;
			}	
		}
		// if the columnth column is won
		if(flag == 1)
		{
			switch(gridValue[row-1][column])
			{
				case 'X':	return 1;
				case 'O':	return 2;
			}
		}
	}
	return 0;
}

//check whether the principal diagonal is won
int GameBoard::checkPrincipalDiagonal()
{
	int i;
	for(i=1; i<SIZE; i++)
		if(gridValue[i-1][i-1] != gridValue[i][i] || gridValue[i][i] == '-')
			return 0;
	switch(gridValue[i-1][i-1])
	{
		case 'X':	return 1;
		case 'O':	return 2;
	}
	return 0;
}

//check whether the non principal diagonal is won
int GameBoard::checkNonPrincipalDiagonal()
{
	int i;
	for(i=1; i<SIZE; i++)
		if(gridValue[i-1][SIZE-i] != gridValue[i][SIZE-i-1] || gridValue[i][SIZE-i-1] == '-')
			return 0;
	switch(gridValue[i-1][SIZE-i])
	{
		case 'X':	return 1;
		case 'O':	return 2;
	}
	return 0;
}

//check if all boxes are already filled
// 0 - not filled, 1 - filled
int GameBoard::checkGridFilled()
{
	for (int row = 0; row < SIZE; row++)
		for(int column=0; column<SIZE; column++)
			if(gridValue[row][column] == '-')
				return 0;
	return 1;
}

//link all the above checks to check the winner
int GameBoard::checkWinner()
{
	if(checkRow()) 					return checkRow();
	if(checkColumn()) 				return checkColumn();
	if(checkPrincipalDiagonal())	return checkPrincipalDiagonal();
	if(checkNonPrincipalDiagonal())	return checkNonPrincipalDiagonal();
	return 0;
}

//check if the game was over
/* Response Legend/Key
	0-Game not over
	1-X won
	2-O won
	3-Grid Filled
*/
int GameBoard::checkGameOver()
{
	//game gets over in two instances
	//1. X or Y won
	if(checkWinner())		return checkWinner();
	//2. Grid is filled
	if(checkGridFilled())	return 3;
	return 0;
}

//print the TIC TAC TOE GRID onto the console
void GameBoard::printGrid()
{
	std::cout << "=================================================\n";
	std::cout << "               THE TIC TAC TOE GRID              \n";
	std::cout << "=================================================\n";

	for (int row = 0; row < SIZE; row++)
	{
		std::cout << "     ";
		for(int column=0; column<SIZE; column++)
			std::cout << "|        |";
		std::cout << "\n     ";
		for(int column=0; column<SIZE; column++)
			std::cout << "|    " << gridValue[row][column] << "   |";
		std::cout << "\n     ";
		for(int column=0; column<SIZE; column++)
			std::cout << "|________|";
		std::cout << "\n";
	}
}

GameBoard::~GameBoard()
{
	
}