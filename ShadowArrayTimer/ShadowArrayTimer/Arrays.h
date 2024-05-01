#pragma once
#include <iostream>
using namespace std;
class shadowarray {
private:
	int* main = new int[4];
	int* sub = new int[8];
	int size{ 0 };
	int capacity{ 4 };
public:
	void insert(int val) {
		if (size == capacity) {
			delete[] main;
			main = sub;
			capacity = capacity * 2;
			sub = new int[capacity * 2];
			main[size] = val;
			sub[size] = val;
		}
		main[size] = val;
		sub[size] = val;
		sub[size - capacity / 2] = main[size - capacity / 2];
		size++;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << main[i] << endl;
		}
	}
};

class lineararr {
private:
	int* main = new int[4];
	int capasity{ 4 };
	int size{ 0 };
	void expander() {
		int* tmp = new int[capasity * 2];
		for (int i = 0; i <= size; i++) {
			tmp[i] = main[i];
		}
		capasity = capasity * 2;
		delete[] main;
		main = tmp;
	}
public:
	void insert(int val) {
		if (size == capasity) {
			expander();
		}
			main[size] = val;
			size++;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << main[i] << endl;
		}
	}
};