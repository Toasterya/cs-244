#include <iostream>
#include <vector>
#include "Hashfuncs.h"
#include <cstdlib>

int main() {

	srand(100);
	cout << "enter test no" << endl;
	cout << "1 first collision   2 first collision requireing 27 steps    3 chain length 53	" << endl << "	4 load facotor 0.9		5 Load factor 1" << endl;
	int testno{ 1 };
	cin >> testno;
	// first collision
	if (testno == 1) {
		int avgcollision{ 0 };
		int count{ 0 };
		for (int j = 0; j < 1000; j++) {
			linearHash linear;
			for (int i = 0; i < 53; i++) {
				int output = linear.hashinsert(rand(), i, 1);
				if (output != 0) {
					count++;
					avgcollision = output + avgcollision;
					//cout << "BREAK" << endl;
					break;
				}
			}
		}
		cout << avgcollision << endl;
		cout << "linear avg over " << count << ": " << float(avgcollision) / 1000.0 << endl;
		avgcollision = 0;
		for (int j = 0; j < 1000; j++) {
			quadHash quad;
			for (int i = 0; i < 53; i++) {
				int output = quad.hashinsert(rand(), i, 1);
				if (output != 0) {
					avgcollision = output + avgcollision;
					//cout << "BREAK" << endl;
					break;
				}
			}
		}
		cout << avgcollision << endl;
		cout << "quad avg over 1000: " << float(avgcollision) / 1000.0 << endl;
		for (int j = 0; j < 1000; j++) {
			Hashchaining hash;
			for (int i = 0; i < 53; i++) {
				int output = hash.hashinsert(rand(), i ,1);
				if (output != 0) {
					avgcollision = output + avgcollision;
					//cout << "BREAK" << endl;
					break;
				}
			}
		}
		cout << avgcollision << endl;
		cout << "chaining avg over 1000: " << float(avgcollision) / 1000.0 << endl;
	}
	else if (testno == 2) {
		// 27 steps of probing  // COUNT 53 IF NONE FOUND
		int avgcollision{ 0 };
		int count{ 0 };
		for (int j = 0; j < 1000; j++) {
			linearHash linear;
			for (int i = 0; i < 53; i++) {
				int output = linear.hashinsert(rand(), i, 2);
				if (output != 0) {
					count++;
					//cout << output << endl;
					avgcollision = output + avgcollision;
					//cout << "BREAK" << endl;
					break;
				}
				else if (i == 52) {
					count++;
					avgcollision = 53 + avgcollision;
					break;
				}
			}
		}
		cout << avgcollision << endl;
		cout << "linear avg over " << count << " " << float(avgcollision) / float(count) << endl;
		// quad
		avgcollision = 0 ;
		count = 0;
		for (int j = 0; j < 1000; j++) {
			quadHash quad;
			for (int i = 0; i < 53; i++) {
				int output = quad.hashinsert(rand(), i, 2);
				if (output != 0) {
					count++;
					avgcollision = output + avgcollision;
					//cout << "BREAK" << endl;
					break;
				}
				else if (i == 52) {
					count++;
					avgcollision = 53 + avgcollision;
					break;
				}
			}
		}
		cout << avgcollision << endl;
		cout << "Quad avg over " << count << " " << float(avgcollision) / float(count) << endl;
		// chaining
		avgcollision = 0;
		count = 0;
		for (int j = 0; j < 1000; j++) {
			Hashchaining hash;
			for (int i = 0; i < 2809; i++) {
				int output = hash.hashinsert(rand(), i, 2);
				if (output != 0) {
					count++;
					avgcollision = output + avgcollision;
					//cout << "BREAK" << endl;
					break;
				}
			}
		}
		cout << avgcollision << endl;
		cout << "Chaining avg over " << count << " " << float(avgcollision) / float(count) << endl;
	}
	else if (testno == 3) {
		int avgcollision{ 0 };
		int count = {0};
		for (int j = 0; j < 1000; j++) {
			Hashchaining hash;
			for (int i = 0; i < 2809; i++) {
				int output = hash.hashinsert(rand(), i, 3);
				//cout << output << endl;
				if (output != 0) {
					count++;
					avgcollision = output + avgcollision;
					//cout << "BREAK" << endl;
					break;
				}
			}
		}
		cout << avgcollision << endl;
		cout << "Chaining avg over " << count << " " << float(avgcollision) / float(count) << endl;
	}
	else if (testno == 4) {
		cout << "Linear load factor of 0.9 requires " << float(53) * float(0.9) << " inserts" << endl;
		cout << "Quadratic load factor of 0.9 requires " << float(53) * float(0.9) << " inserts" << endl;
		cout << "Chaining load factor of 0.9 requires " << float(2908) * float(0.9) << " inserts" << endl;
	}
	else  {
		cout << "Linear load factor of 1 requires " << float(53) * float(1) << " inserts" << endl;
		cout << "Quadratic load factor of 1 requires " << float(53) * float(1) << " inserts" << endl;
		cout << "Chaining load factor of 1 requires " << float(2908) * float(1) << " inserts" << endl;
	}
}