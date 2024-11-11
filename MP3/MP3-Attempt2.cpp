/**
 * File:		TicTacToeGame.cpp
 * Date:		November 10, 2024
 * Author:		Chase McCluskey
 * Description: This program implements a simple Tic Tac Toe game for two players.
 *              It manages the game board, handles player input, checks for win conditions,
 *              and tracks the game statistics.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function prototypes 
int getPlayerInput(string playerName, char board[]);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);
bool boardFull(char board[]);

/** main: The main function that runs the Tic Tac Toe game.
 *        It initializes the game, manages the game loop, and handles player input and game state.
 */
int main() 
{

	//declare player names 
	string player1, player2;
	//initiallize win counters and tie counter 
	int player1Wins = 0, player2Wins = 0, numberOfTies = 0;
	//initialize the game board with default values 
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	//boolean to control the game loop
	bool playAgain = true;
	//characters representing player marks 
	char player1Mark = 'X';
	char player2Mark = 'O';

	//propmt for player names 
	cout << "Enter PLayer 1 name(X): ";
	getline(cin, player1);
	cout << "Enter PLayer 2 name(O): ";
	getline(cin, player2);

	//main game loop 
	while (playAgain)
	{

		//clear and display the board at the start of each game 
		clearBoard(board);
		displayBoard(board);

		//initailize move counter and game over boolean 
		int moves = 0;
		bool gameOver = false;

		//loop to handle each turn until the game is over or the board is full 
		while (!gameOver && moves < 9) 
		{

			//player 1's turn 
			int move = getPlayerInput(player1, board);
			placeMarkOnBoard(board, player1Mark, move);
			displayBoard(board);
			moves++;

			//check to see if player 1 has won 
			if (hasThreeInRow(board, player1Mark)) 
			{
				cout << player1 << " wins!" << endl;
				gameOver = true;
				player1Wins++;
				break;
			}

			//check for tie after player 1's move 
			if (moves == 9) 
			{
				cout << "It's a tie!" << endl;
				numberOfTies++;
				break;
			}

			//player 2's turn 
			move = getPlayerInput(player2, board);
			placeMarkOnBoard(board, player2Mark, move);
			displayBoard(board);
			moves++;

			//check if player 2 has won 
			if (hasThreeInRow(board, player2Mark)) 
			{
				cout << player2 << " wins!" << endl;
				gameOver = true;
				player2Wins++;
			}

			//check for a tie after player 2's move 
			if (moves == 9) 
			{
				cout << "It's a tie!" << endl;
				numberOfTies++;
				break;
			}

		}

		//display the game statistics after each game 
		displayGameStats(numberOfTies, player1Wins, player2Wins);

		//prompt to play again 
		char quit;
		cout << "Do you want to play again? Enter 'Y' or 'y': ";
		cin >> quit;
		playAgain = (quit == 'y' || quit == 'Y');
	}

	//thank players for playing 
	cout << "Thanks for playing!" << endl;

}


/**
 * getPlayerInput:     prompts the player to enter a location on the game board to place their mark.
 *                     Validates the input to ensure it is a number between 1 and 9 and that the move is legal.
 *                     Assuming the Tic Tac Toe marks are 'X' or 'O'
 * @param playerName - the name of the player making the move
 * @param board -      array containing slots for Tic Tac Toe marks.
 *                     Assuming the board has no Tic Tac Toe marks
 * @return the zero-based index of the location where the player wants to place their mark
 */
int getPlayerInput(string playerName, char board[]) 
{

	int location;

	while (true) 
	{

		cout << endl << playerName << " please enter the location you want to place your mark: ";
		cin >> location;
		
		//checks for invalid input 
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a valid number 1-9: ";
			continue;
		}

		//check if location is within valid range 
		if (location >= 1 && location <= 9) 
		{

			if (isLegalMove(board, location)) 
			{
				return location - 1;
			}

			else 
			{
				cout << "That move is not legal, please enter another location\n";
			}
		}

		else 
		{
			cout << "Error in your input, please enter a valid number 1-9\n";
		}

	}

}


/** isLegalMove:    checks if the specified location on the game board is a legal move.
*					Assuming the Tic Tac Toe marks are 'X' or 'O'
* @param board -    array containing slots for Tic Tac Toe marks.
*                   Assuming the board has no Tic Tac Toe marks
* @param location - the position on the board to check for legality
* @return true if the location is not already occupied by 'X' or 'O', otherwise false
*/
bool isLegalMove(char board[], int location) 
{

	return (board[location - 1] != 'X' && board[location - 1] != 'O');

}


/** placeMarkOnBoard:  places the player's mark on the specified location on the game board.
 *                     Assuming the Tic Tac Toe marks are 'X' or 'O'
 * @param board -      array containing slots for Tic Tac Toe marks.
 *                     Assuming the board has no Tic Tac Toe marks
 * @param playerMark - the character representing the player's mark (e.g., 'X' or 'O')
 * @param location -   the position on the board where the mark should be placed
 * @return playermark is placed on the specificed board location 
*/
void placeMarkOnBoard(char board[], char playerMark, int location) 
{

	board[location] = playerMark;

}


/** clearBoard:   resets the game board to its initial state with numbered slots.
 *                Assuming the Tic Tac Toe marks are 'X' or 'O'
 * @param board - array containing slots for Tic Tac Toe marks.
 *                Assuming the board has no Tic Tac Toe marks
 * @return clears board of all player marks, and sets each location back to original location numbers 
 */
void clearBoard(char board[]) 
{

	for (int i = 0; i < 9; i++) 
	{
		board[i] = '1' + i; //converts integer to corresponding chararacter 
	}

}


/** hasThreeInRow: checks if the specified player has three of their marks in a row on the game board. 
*				   Assuming the Tic Tac Toe marks are 'X' or 'O'
* @param board - array containg slots for Tic Tac Toe marks.
*				 Assuming the board has no Tic Tac Toe marks
* @param playerMark - the character representing the players mark (e.g. 'X' or 'O')
* @return true if player has three marks in a row, otherwise false 
*/
bool hasThreeInRow(char board[], char playerMark) 
{

	//Check rows for three in row
	for (int i = 0; i < 9; i += 3) 
	{
		if (board[i] == playerMark && board[i + 1] == playerMark && board[i + 2] == playerMark) 
		{
			return true;
		}
	}

	// Check columns for three in column
	for (int i = 0; i < 3; ++i) 
	{
		if (board[i] == playerMark && board[i + 3] == playerMark && board[i + 6] == playerMark) 
		{
			return true;
		}
	}

	// Check diagonals for three in row 
	if (board[0] == playerMark && board[4] == playerMark && board[8] == playerMark)
	{
		return true;
	}

	if (board[2] == playerMark && board[4] == playerMark && board[6] == playerMark)
	{
		return true;
	}

	//Return false if no three in row, column, or diagonal is found 
	return false;

}


/** displayBoard: displays the current state of the board game.
* 
* @param board -  an array of characters representing the game board
*				  where each element corresponds to a position on the board
* @return prints out a correctly formatted tic tac toe board with locations for players to place their marks on the console
*/
void displayBoard(char board[]) 
{
	cout << "\n " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "---+---+---\n";
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---+---+---\n";
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
}


/** displayGameStats:   displays the game statistics including the scores of both players and the total number of ties.
*					
* @param ties -         the total number of ties in the game
* @param player1Score - the score of player1
* @param player2Score - the score of player2
* @return prints out the gamre statistics to the console 
*/
void displayGameStats(int ties, int player1Score, int player2Score) 
{
	cout << "Player 1's score: " << player1Score << endl;
	cout << "Player 2's score: " << player2Score << endl;
	cout << "Total number of ties: " << ties << endl;

}


/** boardFull:   checks each instance of the Tic Tac Toe board, in the array board.	
*			     Assuming the Tic Tac Toe marks are 'X' or 'O'
* @param board - array containing slots for Tic Tac Toe marks.
*				 Assuming the board has no Tic Tac Toe marks
* @return true if markCounter is 9, or false if markCounter is less than 9, with markCounter starting at 0 
*/
bool boardFull(char board[]) 
{

	int markCounter = 0;

	for (int i = 0; i < 9; i++) 
	{
		if ((board[i] == 'X') || (board[i] == 'O')) 
		{
			markCounter++;
		}
	}

	if (markCounter == 9) 
	{
		return true;
	}

	else
	{ 
		return false; 
	}
}