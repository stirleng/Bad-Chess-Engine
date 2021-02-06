#include <iostream>
#include <string>
using namespace std;

//Global Vars
const int NUM_ROWS = 8;
const int NUM_COLS = 8;
const int NUM_SQUARES = 64;

//Stubs
class Game;
class Board;
class Piece;
class Player;

class Player
{
public:
private:
};

/// <summary>
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// </summary>

class Piece
{
public:
	Piece(char pieceType, string color, int location, Board* board);
	char getType();
	string getColor();
	int getLocation();
	void move(int parsedMove);
	string getAN();
private:
	char m_type;
	string m_color;
	int m_location;
	string m_AN;	//AN == algebraic notation
	Board* m_board;
	int parseMove(string input);
	string LocToAN(int location);
	int ANToLoc(string AN);
};

Piece::Piece(char pieceType, string color, int location, Board* board)
{
	m_type = pieceType;
	m_color = color;
	m_location = location;
	m_board = board;
}

char Piece::getType()
{
	return m_type;
}

string Piece::getColor()
{
	return m_color;
}

int Piece::getLocation()
{
	return m_location;
}

string Piece::getAN()
{
	return m_AN;
}

string LocToAN(int location)
{

}

int ANToLoc(string AN)
{

}

int Piece::parseMove(string move)
{
	//output target square in form of a string of two digits, row # then column #, e.g., 11 would be row 1, column 1
	//I DONT WANT TO LEARN HOW TO DO A FUCKING REGEX
	//I'm probably just going to do conditionals
	if (islower(move.at(0)))
	{
		for (int i = 0; i < move.size(); i++)
		{

		}
	}
	else
	{

	}
}

void Piece::move(int parsedMove)
{
	m_board->move(parsedMove, m_location);
	m_location = parsedMove;		//update location
}

/// <summary>
/// ///////////////////////////////////////////////////////////////////////////////////////////////
/// </summary>

class Board
{
public:
	void move(int parsedMove, int startLocation);
private:
	Piece* m_board[NUM_ROWS][NUM_COLS];
};

Board::Board()
{
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int column = 0; column < NUM_COLS; column++)
		{
			char pieceType = ' ';
			string color;
			switch (column)
			{
			case 1:
			case 8:
				pieceType = 'R';	//Rook
				break;
			case 2:
			case 7:
				pieceType = 'N';	//Knight
				break;
			case 3:
			case 6:
				pieceType = 'B';	//Bishop
				break;
			case 4:
				pieceType = 'Q';	//Queen
				break;
			case 5:
				pieceType = 'K';	//King
				break;
			}
			if (row < 2)
				color = "black";
			if (row > 5)
				color = "white";

			if (pieceType != ' ' && color != "")
				m_board[row][column] = new Piece(pieceType, color, (row * 10) + column, this);
		}
	}
}

void Board::move(int parsedMove, int startLocation)			//move a piece from argument 1 to argument 2
{
	int targetRow = parsedMove / 10;			//get first digit, row
	int targetColumn = parsedMove % 10;			//get second digit, column
	int startRow = startLocation / 10;
	int startColumn = startLocation % 10;
	delete m_board[targetRow][targetColumn];	//clear target square
	m_board[targetRow][targetColumn] = m_board[startRow][startColumn];	//copy the piece over to target square
	m_board[startRow][startColumn] = nullptr;		//clear start square
}



/// <summary>
/// //////////////////////////////////////////////////////////////////////////////////
/// </summary>

class Game 
{
public:
private:
};