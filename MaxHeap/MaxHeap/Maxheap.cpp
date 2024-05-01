#include "MaxHeap.h"

int main() {
	MaxHeap<int> heap;
	heap.insert(2);
	heap.insert(29);
	// should out put 29 THEN 2
	heap.dump();
	cout << endl;

	heap.insert(4);
	heap.insert(23);
	heap.insert(23);
	// should dump 29 23 4 23 2 23
	heap.dump();
	cout << endl;

	cout <<"removed " << heap.removeMax() << endl << endl;
	// should dump 23 23 4 2
	heap.dump();
	cout << endl;
}