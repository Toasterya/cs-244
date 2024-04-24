/*
*	Author: Trevor Kappel 
*    Last Modified: 4/24/24
*/
#pragma once
#include "2Dgrid.h"
#include "iostream"

// IMPORTED CODE from ERIK ANDERSON https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
// end of import
using namespace std;

class HoleintheGridGame {
private:
	LinkedGrid<char>* gamegrid;
	int lives{ 3 };
	Node<char>* player{ nullptr };
	int enemyside{ 5 };
	Node<char>* enemy1{	nullptr	};
	Node<char>* enemy2{ nullptr };
	Node<char>* enemy3{ nullptr };
	Node<char>* enemy4{ nullptr };
	Node<char>* enemy5{ nullptr };
	Node<char>* enemy6{ nullptr };
	Node<char>* enemy7{ nullptr };
	int counter{ 0 };
	// hidden methods
	
	// player start starts the player in the middle square of the 7x7
	void playerplacer() {
		player = gamegrid->getr1c1ptr()->getRight()->getRight()->getRight()->getDown()->getDown()->getDown();
		player->setData(char(225));
	}
	// initillizes enemys and their pointers
	void enemyspawn() {
		enemy1 = nullptr;
		enemy2 = nullptr;
		enemy3 = nullptr;
		enemy4 = nullptr;
		enemy5 = nullptr;
		enemy6 = nullptr;
		enemy7 = nullptr;
		// rand to decide which side they spawn on and for if checks to initiallze the diffrent options 
		Node<char>* current{ gamegrid->getr1c1ptr()};
		int side = rand() % 4;
		enemyside = side;
		// left
		if (side == 0) {
			for (int i = 1; i <= 7; i++) {
				
				switch (i)
				{
				case 1:
					enemy1 = current;
					break;
				case 2:
					enemy2 = current;
					break;
				case 3:
					enemy3 = current;
					break;
				case 4:
					enemy4 = current;
					break;
				case 5:
					enemy5 = current;
					break;
				case 6:
					enemy6 = current;
					break;
				case 7:
					enemy7 = current;
					break;
				default:
					break;
				}
				current->setData(char(206));
				if (current->getDown()->getData() == char(206)) {
					break;
				}
				current = current->getDown();
			}
		}
		// up
		else if (side == 1) {
			for (int i = 1; i <= 7; i++) {
				
				switch (i)
				{
				case 1:
					enemy1 = current;
					break;
				case 2:
					enemy2 = current;
					break;
				case 3:
					enemy3 = current;
					break;
				case 4:
					enemy4 = current;
					break;
				case 5:
					enemy5 = current;
					break;
				case 6:
					enemy6 = current;
					break;
				case 7:
					enemy7 = current;
					break;
				default:
					break;
				}
				current->setData(char(206));
				if (current->getRight()->getData() == char(206)) {
					break;
				}
				current = current->getRight();
			}
		}
		// right
		else if (side == 2) {
			current = current->getLeft();
			for (int i = 1; i <= 7; i++) {
				
				switch (i)
				{
				case 1:
					enemy1 = current;
					break;
				case 2:
					enemy2 = current;
					break;
				case 3:
					enemy3 = current;
					break;
				case 4:
					enemy4 = current;
					break;
				case 5:
					enemy5 = current;
					break;
				case 6:
					enemy6 = current;
					break;
				case 7:
					enemy7 = current;
					break;
				default:
					break;
				}
				current->setData(char(206));
				if (current->getDown()->getData() == char(206)) {
					break;
				}
				current = current->getDown();
			}
		}
		//down
		else {
			current = current->getUp();
			for (int i = 1; i <= 7; i++) {
				switch (i)
				{
				case 1:
					enemy1 = current;
					break;
				case 2:
					enemy2 = current;
					break;
				case 3:
					enemy3 = current;
					break;
				case 4:
					enemy4 = current;
					break;
				case 5:
					enemy5 = current;
					break;
				case 6:
					enemy6 = current;
					break;
				case 7:
					enemy7 = current;
					break;
				default:
					break;
				}
				current->setData(char(206));
				if (current->getRight()->getData() == char(206)) {
					break;
				}
				current = current->getRight();
			}
		}
		
	}
	// reads for arrow key input and moves player while looking for collisions with enemys
	bool playerMove() {
		cout << "Use arrow keys to move" << endl;
		// MODIFIED IMPORTED CODE from ERIK ANDERSON uses the framework for detecing arrow key presses https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
		int c;
		int ex;
		bool anwsered{ false };
		while (anwsered == false)
		{
			c = _getch();

			if (c && c != 224)
			{
				cout << endl << "ERROR: Try arrow keys you enetered: " << (char)c << endl;
			}
			else
			{
				switch (ex = _getch())
				{
				case KEY_UP     /* H */:
					anwsered = true;
					if (player->getUp()->getData() == char(206)) {
						lives--;
						boardreset();
						playerhit();
						
					}
					else {
						player->setData(char(219));
						player = player->getUp();
						player->setData(char(225));
					}
					break;
				case KEY_DOWN   /* K */:
					anwsered = true;
					cout << "Down" << endl;
					if (player->getDown()->getData() == char(206)) {
						lives--;
						boardreset();
						playerhit();
						
					}
					else {
						player->setData(char(219));
						player = player->getDown();
						player->setData(char(225));
					}
					break;
				case KEY_LEFT   /* M */:
					anwsered = true;
					cout << "Left" << endl;
					if (player->getLeft()->getData() == char(206)) {
						lives--;
						boardreset();
						playerhit();
						
		
					}
					else {
						player->setData(char(219));
						player = player->getLeft();
						player->setData(char(225));
					}
					break;
				case KEY_RIGHT: /* P */
					anwsered = true;
					cout << "Right" << endl;
					if (player->getRight()->getData() == char(206)) {
						lives--;
						boardreset();
						playerhit();
					}
					else {
						player->setData(char(219));
						player = player->getRight();
						player->setData(char(225));
					}
					break;
				default:
					break;
				}
				// END OF MODIFIED IMPORTED CODE
			}
		}

		return 0;
	}

	// Moves enemys 1 step foward and checks for collisions with the player
	bool enemyMove() {
		// left
		if (counter == 7) {
			counter = 0;
			boardreset();
			return false;
		}
		else {
			// four similar if statements that progress each enemy depending on the direction the enemys move
			if (enemyside == 0) {
				for (int i = 1; i <= 7; i++) {
					switch (i)
					{
					case 1:
						if (enemy1->getRight()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy1->setData(char(219));
							enemy1 = enemy1->getRight();
							enemy1->setData(char(206));
						}
						break;
					case 2:
						if (enemy2->getRight()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy2->setData(char(219));
							enemy2 = enemy2->getRight();
							enemy2->setData(char(206));
						}
						break;
					case 3:
						if (enemy3->getRight()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy3->setData(char(219));
							enemy3 = enemy3->getRight();
							enemy3->setData(char(206));
						}
						break;
					case 4:
						if (enemy4->getRight()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy4->setData(char(219));
							enemy4 = enemy4->getRight();
							enemy4->setData(char(206));
						}
						break;
					case 5:
						if (enemy5->getRight()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy5->setData(char(219));
							enemy5 = enemy5->getRight();
							enemy5->setData(char(206));
						}
						break;
					case 6:
						if (enemy6->getRight()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy6->setData(char(219));
							enemy6 = enemy6->getRight();
							enemy6->setData(char(206));
						}
						break;
					case 7:
						if (enemy7->getRight()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy7->setData(char(219));
							enemy7 = enemy7->getRight();
							enemy7->setData(char(206));
						}
						break;
					default:
						break;
					}
				}
			}
			// up
			else if (enemyside == 1) {
				for (int i = 1; i <= 7; i++) {
					switch (i)
					{
					case 1:
						if (enemy1->getDown()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy1->setData(char(219));
							enemy1 = enemy1->getDown();
							enemy1->setData(char(206));
						}
						break;
					case 2:
						if (enemy2->getDown()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy2->setData(char(219));
							enemy2 = enemy2->getDown();
							enemy2->setData(char(206));
						}
						break;
					case 3:
						if (enemy3->getDown()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy3->setData(char(219));
							enemy3 = enemy3->getDown();
							enemy3->setData(char(206));
						}
						break;
					case 4:
						if (enemy4->getDown()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy4->setData(char(219));
							enemy4 = enemy4->getDown();
							enemy4->setData(char(206));
						}
						break;
					case 5:
						if (enemy5->getDown()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy5->setData(char(219));
							enemy5 = enemy5->getDown();
							enemy5->setData(char(206));
						}
						break;
					case 6:
						if (enemy6->getDown()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy6->setData(char(219));
							enemy6 = enemy6->getDown();
							enemy6->setData(char(206));
						}
						break;
					case 7:
						if (enemy7->getDown()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy7->setData(char(219));
							enemy7 = enemy7->getDown();
							enemy7->setData(char(206));
						}
						break;
					default:
						break;
					}
				}
			}
			//right
			else if (enemyside == 2) {
				for (int i = 1; i <= 7; i++) {
					switch (i)
					{
					case 1:
						if (enemy1->getLeft()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy1->setData(char(219));
							enemy1 = enemy1->getLeft();
							enemy1->setData(char(206));
						}
						break;
					case 2:
						if (enemy2->getLeft()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy2->setData(char(219));
							enemy2 = enemy2->getLeft();
							enemy2->setData(char(206));
						}
						break;
					case 3:
						if (enemy3->getLeft()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy3->setData(char(219));
							enemy3 = enemy3->getLeft();
							enemy3->setData(char(206));
						}
						break;
					case 4:
						if (enemy4->getLeft()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy4->setData(char(219));
							enemy4 = enemy4->getLeft();
							enemy4->setData(char(206));
						}
						break;
					case 5:
						if (enemy5->getLeft()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy5->setData(char(219));
							enemy5 = enemy5->getLeft();
							enemy5->setData(char(206));
						}
						break;
					case 6:
						if (enemy6->getLeft()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy6->setData(char(219));
							enemy6 = enemy6->getLeft();
							enemy6->setData(char(206));
						}
						break;
					case 7:
						if (enemy7->getLeft()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy7->setData(char(219));
							enemy7 = enemy7->getLeft();
							enemy7->setData(char(206));
						}
						break;
					default:
						break;
					}
				}
			}
			//down
			else {
				for (int i = 1; i <= 7; i++) {
					switch (i)
					{
					case 1:
						if (enemy1->getUp()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy1->setData(char(219));
							enemy1 = enemy1->getUp();
							enemy1->setData(char(206));
						}
						break;
					case 2:
						if (enemy2->getUp()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy2->setData(char(219));
							enemy2 = enemy2->getUp();
							enemy2->setData(char(206));
						}
						break;
					case 3:
						if (enemy3->getUp()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy3->setData(char(219));
							enemy3 = enemy3->getUp();
							enemy3->setData(char(206));
						}
						break;
					case 4:
						if (enemy4->getUp()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy4->setData(char(219));
							enemy4 = enemy4->getUp();
							enemy4->setData(char(206));
						}
						break;
					case 5:
						if (enemy5->getUp()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy5->setData(char(219));
							enemy5 = enemy5->getUp();
							enemy5->setData(char(206));
						}
						break;
					case 6:
						if (enemy6->getUp()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy6->setData(char(219));
							enemy6 = enemy6->getUp();
							enemy6->setData(char(206));
						}
						break;
					case 7:
						if (enemy7->getUp()->getData() == player->getData()) {
							return true;
						}
						else {
							enemy7->setData(char(219));
							enemy7 = enemy7->getUp();
							enemy7->setData(char(206));
						}
						break;
					default:
						break;
					}
				}

			}
			counter++;
			return false;
		}
	}
	// Checks if the player action results in a collision with an enemy
	void playerhit() {
		Node<char>* todel{ player };
		if (player->getX() == 1 && player->getY() == 1) {
			player = player->getRight()->getDown();
		}
		if (player->getX() == 7 && player->getY() == 7) {
			player = player->getLeft()->getUp();
		}
		else if (player->getX() == 7) {
			player = player->getLeft();
		}
		else if (player->getY() == 7) {
			player = player->getUp();
		}
		else if (player->getY() == 1) {
			player = player->getDown();
		}
		else {
			player = player->getRight();
		}
		player->setData(char(225));
		gamegrid->deleter(todel);
	}
	// removes all enemys when called
	void boardreset() {
		enemy1->setData(char(219));
		enemy1 = nullptr;
		enemy2->setData(char(219));
		enemy2 = nullptr;
		enemy3->setData(char(219));
		enemy3 = nullptr;
		enemy4->setData(char(219));
		enemy4 = nullptr;
		enemy5->setData(char(219));
		enemy5 = nullptr;
		enemy6->setData(char(219));
		enemy6 = nullptr;
		enemy7->setData(char(219));
		enemy7 = nullptr;
		enemyspawn();
	}

public:
	// only default can be used
	HoleintheGridGame(){
		gamegrid = new LinkedGrid<char> (true, char(219));
	}

	// METHODS
	
	// RUN ONLY user accessible method
	void run() {
		cout << "KEY|  PLAYER " << char(225) << "		EMPTY SPACE " << char(219) << "		ENEMY " << char(206) << endl;
		playerplacer();
		enemyspawn();
		gamegrid->printboard();
		cout << "LIVES :" << lives << endl;
		bool gamestate{ true };
		while (gamestate){
			playerMove();
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			if (enemyMove()) {
				lives--;
				boardreset();
				playerhit();
				
			}
			gamegrid->printboard();
			cout << "LIVES :" << lives << endl;
			if (lives <= 0) {
				gamestate = false;
				cout << "GAME OVER" << endl;
			}
			cout << endl << endl << endl << endl;
		}
	}
};