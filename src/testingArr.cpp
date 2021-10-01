#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "person.h"
#include "adult.h"

using namespace std;

// // adding a new person to an array
// void addingNewPerson(person ** arr, int * ammount, string name, int age){

//     // when there is nothing in the array at the start of the program
//     if (*ammount == 0){

//         // creating an array of size one
//         arr = new person*[1];

//         // adding an adult with name and age
//         arr[0] = new adult(name, age);
        
//         *ammount++;

//         // printing the name of the person added to the array
//         cout << arr[0]->getPersonName() << endl; // the program works here
//     }
//     else {

//         // init temp array
//         person ** temp;

//         // Creating the temp array to be the right size.
//         temp = new person*[*ammount];

//         // copying everything into the array
//         for (int i = 0; i < *ammount; i++){
//             arr[i] = temp[i];
//         }

//         // deleting the array
//         delete[] arr;

//         *ammount++;

//         // creating the array at the new size
//         arr = new person*[*ammount];

//         // copying everything into the new array
//         for (int i = 0; i < *ammount-1; i++){
//             temp[i] = arr[i];
//         }

//         // adding the new person to the end of the array
//         arr[*ammount-1] = new adult(name, age);

//         // freeing the temp array
//         delete[] temp;

//     }

// }

int main(){

    // // init the array
    // person ** arrayOfPeople;
    // arrayOfPeople = nullptr;

    // int ammount = 0;

    // // adding a new person to the array
    // addingNewPerson(arrayOfPeople, &ammount, "nathaniel", 18);

    // // when I try to print the name of the person here, i get a segmentation
    // // fault.
    // cout << arrayOfPeople[0]->getPersonName() << endl;

    //Trying out vectors

    int ammount = 0;
    string name;
    int age;

    vector<person*> people;

    cout << "How many people: ";
    cin >> ammount;

    for (int i = 0; i < ammount; i++){

        // asking for the name of the person
        cout << "what is the name of the person: ";
        cin >> name;

        //asking for the age of the person
        cout << "What is the age of the person: ";
        cin >> age;

        people.push_back(new adult(name, age));
    }

    for (int i = 0; i < (int)people.size(); i++){
        cout << people[i]->getPersonName() << endl;
    }


    return 0;

}