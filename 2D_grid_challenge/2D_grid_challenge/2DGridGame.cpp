/*
*	Author: Trevor Kappel
*    Last Modified: 4/24/24
*	Estimated total time: 13hrs
*/
#include "2Dgrid.h"
#include "HoleintheGrid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	/*
	// Node minimum viable product
	cout << "Node Testing" << endl;
	Node<int> g{ 3 };
	cout << g.getData() << endl;
	// More Node Tests
	g.setData(91);
	cout << g.getData() << endl;
	Node<int> h{ 6 };
	g.setRight(&h);
	cout << g.getRight()->getData() << endl;
	// Grid testing
	*//*
	cout << endl << "GRID TESTING" << endl;
	LinkedGrid<char> gamegrid(true, char(219));
	cout << gamegrid << endl << endl ;
	gamegrid.getr1c1ptr()->getRight()->getDown()->setData('h');
	gamegrid.getr1c1ptr()->getRight()->getRight()->getDown()->setData('e');
	gamegrid.getr1c1ptr()->getRight()->getRight()->getRight()->getDown()->getDown()->getUp()->setData('l');
	gamegrid.getr1c1ptr()->getLeft()->getLeft()->getLeft()->getDown()->getDown()->getUp()->setData('l');
	gamegrid.getr1c1ptr()->getUp()->getLeft()->getLeft()->getUp()->getUp()->setData('o');
	cout << gamegrid;
	cout << endl << endl;
	gamegrid.deleter(gamegrid.getr1c1ptr()->getUp()->getLeft()->getLeft()->getUp()->getUp());
	gamegrid.deleter(gamegrid.getr1c1ptr());
	cout << gamegrid; */
	srand(time(NULL));
	HoleintheGridGame game;
	game.run();
}