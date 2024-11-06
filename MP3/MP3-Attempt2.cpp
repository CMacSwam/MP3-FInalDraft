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
string getPlayerName();
bool boardFull(char board[]);



int main() {

	bool gameOver = false;
	string player1;
	string player2;
	int player1Wins = 0;
	int player2Wins = 0;
	int numberOfTies = 0;
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int player1Input;
	char player1Mark = 'X';
	char player2Mark = 'O';
	int player2Input;

	player1 = getPlayerName();
	player2 = getPlayerName();

	do {
		displayBoard(board);
		player1Input = getPlayerInput(player1, board);
		placeMarkOnBoard(board, player1Mark, player1Input);
		displayBoard(board);
		player2Input = getPlayerInput(player2, board);
		placeMarkOnBoard(board, player2Mark, player2Input);
		if (hasThreeInRow(board, player1Mark)) {
			player1Wins++;
			clearBoard(board);
			displayGameStats(numberOfTies, player1Wins, player2Wins);
		}
		else if (hasThreeInRow(board, player2Mark)) {
			player2Wins++;
			clearBoard(board);
			displayGameStats(numberOfTies, player1Wins, player2Wins);
		}
		else if (boardFull(board)) {
			numberOfTies++;
			clearBoard(board);
			displayGameStats(numberOfTies, player1Wins, player2Wins);
		}
		else {
			continue;
		}

	} while (!gameOver);
	

}

string getPlayerName() {
	string playerName;
	cout << "Please enter players name: ";
	cin >> playerName;
	cout << endl;
	return playerName;
}

int getPlayerInput(string playerName, char board[]) {

	int location;

	while (true) {

		cout << endl << playerName << " please enter the location you want to place your mark: ";
		cin >> location;
		
		if (location >= 1 && location <= 9) {
			if (isLegalMove(board, location)) {
				if (board[location - 1] == ('X' || 'O')) {
					cout << "That location is already taken, please enter another location\n";
				}
				else {
					return location - 1;
					break;
				}
			}
		}
		else {
			cout << "Error in your input, please enter a valid number 1-9\n";
		}
	}

}


bool isLegalMove(char board[], int location) {

	if ((board[location] == 'O') || (board[location] == 'X')) {
		return false;
	}
	else; return true;

}

void placeMarkOnBoard(char board[], char playerMark, int location) {

	if (isLegalMove(board, location)) {
		board[location] = playerMark;
	}
	else {
		while (true) {
			cout << "Not a legal move, please enter another mark('X' or 'O'): ";
			cin >> location;
			if (isLegalMove(board, location)) {
				board[location] = playerMark;
				break;
			}
		}
	}

}

void clearBoard(char board[]) {

	for (int i = 9; i >= 0; i--) {
		board[i] = i;
	}

}

bool hasThreeInRow(char board[], char playerMark) {

	//Needs Work

	//possibly add switch statement
	if ((playerMark == board[0]) && (playerMark == board[1]) && (playerMark == board[2])) {
		return true;
	}
	else if ((playerMark == board[3]) && (playerMark == board[4]) && (playerMark == board[5])) {
		return true;
	}
	else if ((playerMark == board[6]) && (playerMark == board[7]) && (playerMark == board[8])) {
		return true;
	}
	else if((playerMark == board[0]) && (playerMark == board[3]) && (playerMark == board[6])) {
		return true;
	}
	else if ((playerMark == board[1]) && (playerMark == board[4]) && (playerMark == board[7])) {
		return true;
	}
	else if ((playerMark == board[2]) && (playerMark == board[5]) && (playerMark == board[8])) {
		return true;
	}
	else if ((playerMark == board[0]) && (playerMark == board[4]) && (playerMark == board[8])) {
		return true;
	}
	else if ((playerMark == board[6]) && (playerMark == board[4]) && (playerMark == board[2])) {
		return true;
	}
	else {
		return false;
	}


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
	cout << "Total number of ties: " << ties;

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