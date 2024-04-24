#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class stringHash {
private:
	vector<string> arr;

public:
	stringHash() {
		arr.assign(31, "");
		cout << arr.size() << endl;
	}
	bool hashinsert(string word) {
		cout << "adding " << word << " ";
		int n{ 1 };
		int index = int(word.front() * word.at(1) * word.at(2)) % 31;
		// checks if blank then if it is it increments to the end of the list looking for blank
		if (arr.at(index) != "") {
			cout << "COLLISION at index " << index << endl;
			while (arr.at(index + n) != "") {
				// if no blank is found by end of list it then starts looking at the beginning
				if (index + n == 30) {
					n = -index;
				}
				else {
					n++;
				}
			}
			arr[index + n] = word;
			return true;
		}
		else {
			cout << endl;
			arr[index] = word;
			return false;
		}
	}
	bool lookup(string word) {
		int index = int(word.front() * word.at(1) * word.at(2)) % 31;
		int n = 0;
		bool loopcheck{ false };
		// checks every consecutive filled index and loops to front if at end
		while (arr.at(index + n) != "") {
			if (arr.at(index + n) == word) {
				return true;
			}
			if (index + n == 30) {
				n = -index;
				loopcheck = true;
			}
			// ends if gets back to original int
			if (index + n == index && loopcheck ) {
				return false;
			}
			n++;
		}
		return false;
	}
	vector<string> dump(){
		return arr;
	}
};