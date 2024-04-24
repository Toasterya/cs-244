#include <iostream>
#include <string>
#include "Hashfunc.h"
#include <vector>
using namespace std;
// it will take 12 addionts before collision
int main() {
	// creates a bank of wrods and asks how many of them you want to add
	int additions;
	string wordarr[31] = { "deli", "ham", "turkey", "frosting", "salami", "bread" , "wheat" , "flour" , "milk", "eggs",
		"cake" , "frosting" , "loaf" , "rat", "cat", "trap" , "wendnesday" , "sock" , "goad", "jeans",
		"pillow" , "reverberate" , "pokemon" , "sword", "halberd", "scimitar" , "grimsnarl" , "evocation" , "necromancy", "conjuration", "quail" };
	cout << "add how many: ";
	cin >> additions;
	stringHash g;
	for (int i = 0; i < additions; i++) {
		g.hashinsert(wordarr[i]);
	}

	// prints table
	vector<string> arr{ g.dump() };
	for (int i = 0; i < arr.size(); i++) {
		cout << "index " << i << " : " << arr[i] << endl;
	}
	// testing lookup
	cout << "looking for necromancy" << endl;
	if (g.lookup("necromancy")) {
		cout << "necromancy true" << endl;
	}
	else {
		cout << "necromancy false" << endl;
	}
	cout << "looking for eggloaf" << endl;
	if (g.lookup("eggloaf")) {
		cout << "eggloaf true" << endl;
	}
	else {
		cout << "eggloaf false" << endl;
	}



}