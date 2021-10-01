#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "adult.h"

using namespace std;

void addPerson(vector<person*> &apple, int * ammount){

    string name;
    int age;

    for (int i = 0; i < *ammount; i++){

        // asking for the name of the person
        cout << "what is the name of the person: ";
        cin >> name;

        //asking for the age of the person
        cout << "What is the age of the person: ";
        cin >> age;

        apple.push_back(new adult(name, age));
    }

}

int main(){

    //Trying out vectors

    int ammount = 0;

    vector<person*> people;

    cout << "How many people: ";
    cin >> ammount;

    addPerson(people, &ammount);

    cout << (int)people.size() << endl;

    for (int i = 0; i < ammount; i++){
        cout << people[i]->getPersonName() << endl;
    }


    return 0;

}