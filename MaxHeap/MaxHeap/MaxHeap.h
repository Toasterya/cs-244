#pragma once
#include <vector>
using namespace std;

template <typename T>
class MaxHeap {
private:
	vector<T> data;
	int size{ 0 };

	// Helpers
	void reheapifyUp(int index) {
		// base case
		if (index == 1) { return; }
		// look at parent index if index is greater then switch and recurse
		int parent{ index / 2 };
		if (data[index] > data[parent]) {
			T tmp{ data[parent] };
			data[parent] = data[index];
			data[index] = tmp;
			// recurse
			reheapifyUp(parent);
		}
	}
	void reheapifyDown(int index) {
		// base case
		if (2* index > size) {
			return;
		}
		int leftChild{ 2 * index };
		if (2 * index + 1 > size) {
			T tmp = data[index];
			data[index] = data[leftChild];
			data[leftChild] = tmp;
			return;
		}
		// children
		
		int rightChild{ 2 * index + 1 };
		if (data[index] < data[leftChild] || data[index] < data[index]) {
			if (data[index] < data[rightChild]) {
				T tmp = data[index];
				data[index] = data[rightChild];
				data[rightChild] = tmp;
				reheapifyDown(rightChild);
			}
			else {
				T tmp = data[ index ];
				data[index] = data[leftChild];
				data[leftChild] = tmp;
				reheapifyDown(leftChild);
			}
			
		}
	}
public:

	int getSize() { return size; }

	// root always at index 1 with max val
	T peek() { return data[1]; }

	void insert(T val) {
		//step 1. maintain shape
		if (data.size() - 1 <= size) {
			data.push_back(val);
		}
		else {
			data[size + 1] = val;
		}
		size++;
		// step 2 reheapify to maintain order
		reheapifyUp(size);
	}

	T removeMax() {
		// step 1 maintain shape
		if (size > 2) {
			T valtoreturn = data[1];
			data[1] = data[size];
			data.erase(size);
			size--;
			return valtoreturn;
		}
		else if (size == 1) {
			size--;
			return data[1];
		}
		else {
			return;
		}
		// reheapify down
		reheapifyDown(1);

	}

};