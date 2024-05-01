#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class linearHash {
private:
	vector<int> arr;

public:
	linearHash() {
		arr.assign(53, 0);
	}
	int hashinsert(int val, int i, int testnum) {
		//cout << "adding " << val << " ";
		int n{ 1 };
		int index = val % 52;
		// checks if blank then if it is it increments to the end of the list looking for blank
		if (arr.at(index) != 0) {
			//cout << "COLLISION at index " << index << endl;
			while (arr.at(index + n) != 0) {
				// if no blank is found by end of list it then starts looking at the beginning
				if (testnum == 2) {
					if (n >= 27) {
						return i;
					}
				}
				//
				if (index + n == 52) {
					n = -index;
				}
				else {
					n++;
				}
			}
			arr[index + n] = val;
			// for test 1
			if (testnum == 1) {
				 return i;
			}
			// for test 2
			else if (testnum == 2) {
				return 0;
			}
		}
		else {
			//cout << endl;
			arr[index] = val;
			return 0;
		}
	}
	bool lookup(int val) {
		int index = val % 53;
		int n = 0;
		bool loopcheck{ false };
		// checks every consecutive filled index and loops to front if at end
		while (arr.at(index + n) != 0) {
			if (arr.at(index + n) == val) {
				return true;
			}
			if (index + n == 30) {
				n = -index;
				loopcheck = true;
			}
			// ends if gets back to original int
			if (index + n == index && loopcheck) {
				return false;
			}
			n++;
		}
		return false;
	}
	void dump() {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr.at(i) << endl;
		}
	}
};

class quadHash {
private:
	vector<int> arr;

public:
	quadHash() {
		arr.assign(53, 0);
	}
	int hashinsert(int val, int j, int testno) {
		//cout << "adding " << val << " ";
		unsigned int n{ 1 };
		int multiple{ 2 };
		int i = 1;
		int counter{ 0 };
		int index = val % 52;
		// checks if blank then if it is it increments to the end of the list looking for blank
		if (arr.at(index) != 0) {
			//cout << "COLLISION at index " << index << endl;
			while (arr.at(index + n) != 0) {
				//cout << "now checking index +" << n << endl;
				// if no blank is found by end of list it then starts looking at the beginning
				if (testno == 2) {
					if (counter >= 27) {
						return j;
					}
				}
				if (index + n == 52) {
					n = -index + multiple * multiple;
					multiple++;
				}
				else {
					n = multiple * multiple;
					while (index + n >= 52) {
						n = -index * i + multiple * multiple;
						i++;
						
						if (i > 100) {
							//cout << "could not insert" << endl;
							return 0;
						}
					}
					multiple++;
				}
				counter++;
			}
			arr[index + n] = val;
			if (testno == 1) {
				return j;
			}
			else {
				return 0;
			}
		}
		else {
			//cout << endl;
			arr[index] = val;
			return 0;
		}
	}
	bool lookup(int val) {
		int index = val % 53;
		int n = 0;
		bool loopcheck{ false };
		// checks every consecutive filled index and loops to front if at end
		while (arr.at(index + n) != 0) {
			if (arr.at(index + n) == val) {
				return true;
			}
			if (index + n == 30) {
				n = -index;
				loopcheck = true;
			}
			// ends if gets back to original int
			if (index + n == index && loopcheck) {
				return false;
			}
			n++;
		}
		return false;
	}
	void dump() {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr.at(i) << endl;
		}
	}

};
template <typename T>
class hashnode {
private:
	T data{ 0 };
	hashnode<T>* next{ nullptr };

public:
	hashnode(T d){
		data = d;
	}
	hashnode<T>* getNext() { return next; }
	void setNext(hashnode<T>* n) { next = n; }
	T getData(){ return data; }
	void setData(T d) { data = d; }
};

class Hashchaining {
private:
	vector<hashnode<int>*> arr;
public:
	Hashchaining() {
		for (int i = 0; i < 53; i++) {
			hashnode<int>* def = new hashnode<int>(0);
			arr.push_back(def);
		}
	}
	int hashinsert(int val, int i, int testno) {
		//cout << "adding " << val << endl;
		int index = val % 52;
		int count{ 0 };
		hashnode<int>* indexnode = arr.at(index);
		//cout << arr[index]->getData() << " at "<< index << endl;
		// checks if blank
		if (indexnode->getData() != 0) {
			//cout << "COLLISION at index " << index << endl;
			while (indexnode->getNext() != nullptr) {
				indexnode = indexnode->getNext();
				count++;

				if (testno == 2) {
					if (count >= 27) {
						return i;
					}
				}
				if (count == 53) {
					if (testno == 3) {
						return i;
					}
					else {
						exit(i);
					}
				}
			}
			hashnode<int>* fabnode= new hashnode<int>{ val };
			indexnode->setNext(fabnode);
			if (testno == 1) {
				return i;
			}
			else {
				return 0;
			}
		}
		else {
			//cout << endl;
			arr[index]->setData(val);
			return 0;
		}
	}
	void print() {
		for (int i = 0; i < 53; i++) {
			//cout << "chain " << i << endl;
			hashnode<int>* current = arr[i];
			while (current->getNext() != nullptr) {
				if (current->getData() != 0) {
					cout << current->getData() << endl;
					current = current->getNext();
				}
			}
			cout << current->getData() << endl;
		}
	}
};