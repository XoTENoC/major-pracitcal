#include "../../src/classes/person.h"
#include "../../src/classes/child.h"
#include <iostream>

using namespace std;

int main(){
	// Initialising and setting variables.
	string name;
	int age;

	cout << "Please input a name: ";
	cin >> name;
	cout << "Please input an age: ";
	cin >> age;

	// Creating an child object.
	child testChild(name, age);

	// Testing getters.
	cout << "name = " << testChild.getPersonName() << endl;
	cout << "age = " << testChild.getAge() << endl;

	// Testing setters.
	string newName;
	cout << "Please enter a new name: ";
	cin >> newName;
	testChild.setPersonName(newName);
	cout << "name = " << testChild.getPersonName() << endl;

	int newAge;
	cout << "Please enter a new age: ";
	cin >> newAge;
	testChild.setAge(newAge);
	cout << "age = " << testChild.getAge() << endl;

	// Testing Contact information.
}

