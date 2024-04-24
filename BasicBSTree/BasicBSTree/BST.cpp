#include "BST.h"


int main() {
	BinarySearchTree<int> g;
	g.insert(50);
	g.insert(45);
	g.insert(70);
	g.insert(20);
	g.insert(47);
	g.insert(60);
	g.insert(80);
	g.insert(100);
	cout << "looking up 150 " << g.lookup(150) << endl;
	cout << "looking up 50 " << g.lookup(50) << endl;
	cout << "looking up 100 " << g.lookup(100) << endl;
	cout << "looking up 60 " << g.lookup(60) << endl;
	g.print();
	cout << "TESTING case 1 deleting 20" << endl;
	g.remove(20);
	g.print();
	cout << "TESTING case 2 deleting 80" << endl;
	g.remove(80);
	g.print();
	cout << "TESTING case 3 deleting 70" << endl;
	g.remove(70);
	g.print();
	cout << g.getRoot()->right->data << endl;
}