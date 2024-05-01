#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>
#include <fstream>
#include "Arrays.h"
using namespace std::chrono;
int main() {
	ofstream Datafile("Datafile.txt");
	cout << "file opened" << endl;
	int trialsize{10000};
	double totalval{ 0.0 };
	lineararr liner;
	shadowarray shad;
	vector<int> vecarr;
	shadowarray atdata;
	int choice{0};
	//cout << "1 : linear	" << "2:shadow	" << " 3: Vector" << endl;
	//cin >> choice;
	//if (choice == 1) {
		for (int i = 0; i < trialsize; i++) {
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			liner.insert(i);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time = duration_cast<duration<double>>(t2 - t1);
			totalval = totalval + time.count();
			double avg = totalval / i;
			Datafile << time.count() << "," << i << ";";
			/*
			if (avg * 5 < time.count()) {
				cout << time.count() << endl;
				atdata.insert(i);
			}
			else if (i % 60606 == 2) {
				cout << time.count() << endl;
				atdata.insert(i);
			}
			*/
		}
	//}
	//else if (choice == 2) {
		cout << "shadow" << endl;
		Datafile << endl;
		for (int i = 0; i < trialsize; i++) {
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			shad.insert(i);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time = duration_cast<duration<double>>(t2 - t1);
			totalval = totalval + time.count();
			double avg = totalval / i;

			Datafile << time.count() << "," << i << ";";
			/*
			if (avg * 5 < time.count()) {
				cout << time.count() << endl;
				atdata.insert(i);
			}
			else if (i % 60606 == 2) {
				cout << time.count() << endl;
				atdata.insert(i);
			}
			*/
		}
	//}
	//else {
		cout << "vector" << endl;
		Datafile << endl;
		for (int i = 0; i < trialsize; i++) {
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			vecarr.push_back(i);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time = duration_cast<duration<double>>(t2 - t1);
			totalval = totalval + time.count();
			double avg = totalval / i;
			Datafile << time.count() << "," << i << ";";
			/*
			if (avg * 8 < time.count()) {
				cout << time.count() << endl;
				atdata.insert(i);
			}
			else if (i % 6060606 == 2) {
				cout << time.count() << endl;
				atdata.insert(i);
			}
			*/
		}
	//}
	/*
	cout << "avg: " << totalval / trialsize;
	cout << endl << endl << endl << "index" << endl << endl << endl;
	atdata.print();
	*/

	Datafile.close();
	cout << "file closed" << endl;
	
}