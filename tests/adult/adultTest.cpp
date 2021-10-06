#include "../../src/classes/person.h"
#include "../../src/classes/adult.h"
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

	// Creating an adult object.
	adult testAdult(name, age);

	// Testing getters.
	cout << "name = " << testAdult.getPersonName() << endl;
	cout << "age = " << testAdult.getAge() << endl;

	// Testing setters.
	string newName;
	cout << "Please enter a new name: ";
	cin >> newName;
	testAdult.setPersonName(newName);
	cout << "name = " << testAdult.getPersonName() << endl;

	int newAge;
	cout << "Please enter a new age: ";
	cin >> newAge;
	testAdult.setAge(newAge);
	cout << "age = " << testAdult.getAge() << endl;

	// Testing Working with children number.
	string workingWithChildren;
	cout << "Please enter a working with children number: ";
	cin >> workingWithChildren;
	testAdult.setWorkingWithChildrenNumber(workingWithChildren);
	cout << "Working with children number = " << testAdult.getWorkingWithChildrenNumber() << endl;

	// Testing Contact information.
}

