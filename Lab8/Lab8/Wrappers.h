#pragma once
#include <vector>
#include <iostream>
using namespace std;
template <typename T>
class SecretStructure {
public:
	SecretStructure() {};
	virtual void add(T data) = 0;
	virtual T remove() = 0;
	virtual T peek() = 0;
	virtual int size() = 0;
};

template <typename T>
class SecretStack : public SecretStructure<T> {
private:
	vector<T> arr;
public:
	SecretStack() {};
	void add(T data) { arr.push_back(data);}
	// gets data removes last and returns data
	T remove(){
		T value = arr.back();
		arr.pop_back();
		return value; }
	T peek() { return arr.back(); }
	int size() { return arr.size(); }
};

template <typename T>
class SecretQueue : public SecretStructure<T> {
private:
	vector<T> Queuearr;
public:
	SecretQueue() {};
	 // adds data to front
	void add( T d) { Queuearr.insert(Queuearr.begin(), d); }
	//gets data removes back and returns data
	T remove() {
		T value = Queuearr.back();
		Queuearr.pop_back();
		return value;
	}
	T peek() { return Queuearr.back(); }
	int size() { return Queuearr.size(); }
};