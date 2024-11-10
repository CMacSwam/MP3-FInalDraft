/*
* Author: Chase McCluskey
* Date:11/3/2024
* File:MP3 - Tic Tac D'Oh
*
* Description: Implement functions and arrays to create a tic tac toe game
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int getPlayerInput(string playerName, char board[]);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);
bool boardFull(char board[]);



int main() {

	
	string player1, player2;
	int player1Wins = 0, player2Wins = 0, numberOfTies = 0;
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	bool playAgain = true;
	int currentPlayer = 1;
	char player1Mark = 'X';
	char player2Mark = 'O';

	cout << "Enter PLayer 1 name(X): ";
	getline(cin, player1);
	cout << "Enter PLayer 2 name(O): ";
	getline(cin, player2);

	while (playAgain) {

		clearBoard(board);
		displayBoard(board);

		int moves = 0;
		bool gameOver = false;

		while (!gameOver && moves < 9) {
			

			int move = getPlayerInput(player1, board);
			placeMarkOnBoard(board, player1Mark, move);
			displayBoard(board);
			moves++;

			if (hasThreeInRow(board, player1Mark)) {
				cout << player1 << " wins!" << endl;
				gameOver = true;
				player1Wins++;
				break;
			}
			if (moves == 9) {
				cout << "It's a tie!" << endl;
				numberOfTies++;
				break;
			}

			move = getPlayerInput(player2, board);
			placeMarkOnBoard(board, player2Mark, move);
			displayBoard(board);
			moves++;

			if (hasThreeInRow(board, player2Mark)) {
				cout << player2 << " wins!" << endl;
				gameOver = true;
				player2Wins++;
			}

			if (moves == 9) {
				cout << "It's a tie!" << endl;
				numberOfTies++;
				break;
			}
		}

		displayGameStats(numberOfTies, player1Wins, player2Wins);

		char quit;
		cout << "Do you want to play again? Enter 'Y' or 'y': ";
		cin >> quit;
		playAgain = (quit == 'y' || quit == 'Y');
	}

	cout << "Thanks for playing!" << endl;

}


int getPlayerInput(string playerName, char board[]) {

	int location;

	while (true) {

		cout << endl << playerName << " please enter the location you want to place your mark: ";
		cin >> location;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a valid number 1-9: ";
			continue;
		}

		if (location >= 1 && location <= 9) {
			if (isLegalMove(board, location)) {
				return location - 1;
			}
			else {
				cout << "That move is not legal, please enter another location\n";
			}
		}
		else {
			cout << "Error in your input, please enter a valid number 1-9\n";
		}
	}

}


bool isLegalMove(char board[], int location) {

	return (board[location - 1] != 'X' && board[location - 1] != 'O');

}

void placeMarkOnBoard(char board[], char playerMark, int location) {

	board[location] = playerMark;

}

void clearBoard(char board[]) {

	for (int i = 0; i < 9; i++) {
		board[i] = '1' + i; //converts integer to corresponding chararacter 
	}

}

bool hasThreeInRow(char board[], char playerMark) {

	//Needs Work

	//possibly add switch statement
	for (int i = 0; i < 9; i += 3) {
		if (board[i] == playerMark && board[i + 1] == playerMark && board[i + 2] == playerMark) {
			return true;
		}
	}
	// Check columns
	for (int i = 0; i < 3; ++i) {
		if (board[i] == playerMark && board[i + 3] == playerMark && board[i + 6] == playerMark) {
			return true;
		}
	}
	// Check diagonals
	if (board[0] == playerMark && board[4] == playerMark && board[8] == playerMark) return true;
	if (board[2] == playerMark && board[4] == playerMark && board[6] == playerMark) return true;

	return false;

}

void displayBoard(char board[]) {
	cout << "\n " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "---+---+---\n";
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---+---+---\n";
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
}

void displayGameStats(int ties, int player1Score, int player2Score) {

	cout << "Player 1's score: " << player1Score << endl;
	cout << "Player 2's score: " << player2Score << endl;
	cout << "Total number of ties: " << ties << endl;

}

bool boardFull(char board[]) {

	int markCounter = 0;

	for (int i = 0; i < 9; i++) {
		if ((board[i] == 'X') || (board[i] == 'O')) {
			markCounter++;
		}
	}
	if (markCounter == 9) {
		return true;
	}
	else { return false; }
}