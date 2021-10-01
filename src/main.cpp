#include <iostream>
#include <string>
#include "classes/roster.h"
#include "classes/person.h"
#include "classes/adult.h"
#include "classes/child.h"
#include "classes/events.h"

using namespace std;

void addPerson(person ** arr, int * ammount){
    person ** tempArrayOfPerople;
    int size = *ammount;
    int option = 0;
    bool isTrue = true;
    string name;
    int age, competency;
    adult newAdult("name", 0);
    child newChild("name", 0);

    // picking whether you are adding a Adult or Child
    while(isTrue){
        cout << "1 - To add an Adult" << endl;
        cout << "2 - To add a Child" << endl;
        cout << "3 - Exit" << endl;
        cin >> option;

        switch (option){
            case 1:
                isTrue = false;
                break;
            case 2:
                isTrue = false;

                break;
            case 3:
                isTrue = false;
                break;
        }
    }

}

void viewAllPeople(person ** arr, int * ammount){

    for (int i = 0; i < *ammount; i++){
        cout << i + 1 << " : ";
        cout << endl;
    }

}

int main(){

    // Starting the program
    bool inProgram = true;
    bool mainMenu = true;

    int choice = 0;

    while(inProgram){
        // MAIN MENU
        mainMenu = true;
        while(mainMenu){
            cout << "1 - Add a new person" << endl;
            cout << "2 - View all the people" << endl;
            cout << "3 - Create a roster" << endl;
            cout << "4 - View roster" << endl;
            cout << "5 - Exit" << endl;

            cin >> choice;

            switch(choice){
                // adding a person the array of people
                case 1:
                    mainMenu = false;
                    break;
                case 2:
                    mainMenu = false;
                    // viewAllPeople(arrayOfPeople, &numberOfPeople);
                    break;
                case 3:
                    mainMenu = false;
                    break;
                case 4:
                    mainMenu = false;
                    break;
                case 5:
                    mainMenu = false;
                    inProgram = false;
                    break;
            }
        }

    }

}