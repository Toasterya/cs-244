/*
*	Author: Trevor Kappel
*    Last Modified: 4/24/24
*/
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
	T data;
	int Xpos{ 1 };
	int Ypos{ 1 };
	Node<T>* up{ nullptr };
	Node<T>* down{ nullptr };
	Node<T>* left{ nullptr };
	Node<T>* right{ nullptr };
public:
	Node(T d) {
		data = d;
	}
	Node(T d, int x, int y) {
		data = d;
		Xpos = x;
		Ypos = y;
	}
	T getData() {
		return data;
	}
	void setData(T newdata) {
		data = newdata;
	}
	Node<T>* getUp() {
		return up;
	}
	Node<T>* getDown() {
		return down;
	}
	Node<T>* getLeft() {
		return left;
	}
	Node<T>* getRight() {
		return right;
	}
	int getX() { return Xpos; }
	int getY() { return Ypos; }

	void setUp(Node<T>* node) {
		up = node;
	}
	void setDown(Node<T>* node) {
		down = node;
	}
	void setLeft(Node<T>* node) {
		left = node;
	}
	void setRight(Node<T>* node) {
		right = node;
	}
};
template <typename T>
class LinkedGrid {
private:
	Node<T>* r1c1ptr{ nullptr };

public:
	LinkedGrid() {

	}
	// automaticly creates a 7 by 7 linked grid for the user with uniform data 
	LinkedGrid(bool prefab, T d) {
		if (prefab) {
			Node<T>* newNode{ new Node<T>{d,1,1} };
			r1c1ptr = newNode;
			Node<T>* current{ r1c1ptr };
			Node<T>* linker{ r1c1ptr };
			// y creation
			for (int j = 1; j < 8; j++) {
				// x creation
				for (int i = 2; i < 8; i++) {
					Node<T>* fabnode = new Node<T>{ d,i,j };
					// for testing
				//	cout << "setting " << i << "," << j << endl;
				
				//	cout << "(" << fabnode->getX() << "," << fabnode->getY() << ")" << " value: " << fabnode->getData() << endl;
				//	cout << "(" << current->getX() << "," << current->getY() << ")" << " value: " << current->getData() << endl;
					current->setRight(fabnode);
					fabnode->setLeft(current);
					if (j > 1) {
						// more test outputs
						//cout << "linker at (" << linker->getX() << "," << linker->getY() << ")" << endl;
						//cout << "linking with fab at (" << fabnode->getX() << "," << fabnode->getY() << ")" << endl;
						linker->setDown(fabnode);
						fabnode->setUp(linker);
						linker = linker->getRight();
					}
					current = fabnode;
					
				}
				linker = r1c1ptr;
				current = r1c1ptr;
				// moving linker and current down to new height
				for (int k = 1; k < j; k++) {
					current = current->getDown();
					linker = linker->getDown();
				}
				Node<T>* fabnode = new Node<T>{ d,1,j+1 };
				current->setDown(fabnode);
				fabnode->setUp(current);
				current = fabnode;
				linker = linker->getRight();
			}

		}
		else {
			exit(50123);
		}
		horizontallinker();
		verticallinker();
	}
	// links first coloumn and last coloumn creating loops
	void horizontallinker() {
		Node<T>* front{r1c1ptr};
		Node<T>* back{ r1c1ptr->getRight()->getRight()->getRight()->getRight()->getRight()->getRight() };
		for (int p = 1; p <= 7; p++) {
			front->setLeft(back);
			back->setRight(front);
			front = front->getDown();
			back = back->getDown();
		}
	}
	// links top row to bottom row creating loops
	void verticallinker() {
		Node<T>* top{ r1c1ptr };
		Node<T>* bottom{ r1c1ptr->getDown()->getDown()->getDown()->getDown()->getDown()->getDown() };
		for (int p = 1; p <= 7; p++) {
			top->setUp(bottom);
			bottom->setDown(top);
			top = top->getRight();
			bottom = bottom->getRight();
		}
	}
	Node<T>* getr1c1ptr() {
		return r1c1ptr;
	}
	// Prints out board in the same way as the operator overload- exisits becuse .h file couldnt call operator overload
	void printboard() {
		Node<T>* current{ r1c1ptr };
		for (int i = 1; i <= 7; i++) {
			int lastx{ 0 };
			for (int j = 1; j <= 7; j++) {
				if (current->getX() == lastx + 1 && current->getY() == i) {
					cout << "	 " << current->getData();
					current = current->getRight();
				}
				else {
					cout << "	 ";
				}
				lastx++;
				
			}
			current = r1c1ptr;
			for (int k = 1; k <= i; k++) {
				current = current->getDown();
			}
			cout << endl << endl;
		}
	}
	// deletes any node except for root;
	void deleter(Node<T>* todel) {
		if (todel == r1c1ptr) {
			return;
		}
		Node<T>* left{ todel->getLeft()};
		Node<T>* up{ todel->getUp()};
		Node<T>* right{ todel->getRight()};
		Node<T>* down{ todel->getDown()};
		left->setRight(right);
		right->setLeft(left);
		up->setDown(down);
		down->setUp(up);
		
		delete todel;
	}

	template <typename T>
	friend ostream& operator<< (ostream& out, const LinkedGrid<T>& grid);
	};
	// Operator overload prints out grid by using expected data
	template <typename T>
	ostream& operator<< (ostream& out, const LinkedGrid<T>& grid) {
		Node<T>* current{ grid.r1c1ptr };
		for (int i = 1; i <= 7; i++) {
			int lastx{ 0 };
			for (int j = 1; j <= 7; j++) {
				if (current->getX() == lastx + 1 && current->getY() == i) {
					out << "	 " << current->getData();
					current = current->getRight();
				}
				else {
					//cout << "if failed x: " << current->getX() << "   expected x: " << lastx + 1 << "   y : " << current->getY() << " expected: " << i << endl;
					out << "	";
				}
				lastx++;
				
			}
			current = grid.r1c1ptr;
			for (int k = 1; k <= i; k++) {
				current = current->getDown();
			}
			out << endl << endl;
		}
		return out;
	}
