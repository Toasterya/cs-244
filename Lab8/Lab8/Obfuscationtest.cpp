#include "Wrappers.h"
#include <iostream>
using namespace std;
int main() {
	SecretQueue<int> secret;
	// TESTING
	/*
	SecretStack<int> a;
	SecretQueue<int> b;
	for (int i = 1; i < 11; i++) {
		a.add(i);
		b.add(i);
	}
	SecretStructure<int>* c = dynamic_cast<SecretStructure<int>*>(&a);
	SecretStructure<int>* d = dynamic_cast<SecretStructure<int>*>(&b);
	cout << c->peek() << endl;
	c->add(20);
	cout << c->remove() << endl;
	cout << d->peek() << endl;
	d->add(20);
	cout << d->remove() << endl;
	SecretStack<int>* e = dynamic_cast<SecretStack<int>*>(c);
	SecretQueue<int>* f = dynamic_cast<SecretQueue<int>*>(d);
	cout << e->peek() << endl;
	e->add(5);
	cout << e->remove() << endl;
	cout << f->peek() << endl;
	f->add(5);
	cout << f->remove() << endl;
	*/

	
	SecretStructure<int>* upcastedsecret= dynamic_cast<SecretStructure<int>*>(&secret);

	cout << "input int to add : ";
	int din;
	cin >> din;
	upcastedsecret->add(din);
	cout << "input int to add : ";
	cin >> din;
	upcastedsecret->add(din);
	cout << "removing 1 int" << endl;
	cout << "removed: " << upcastedsecret->remove() << endl;



}