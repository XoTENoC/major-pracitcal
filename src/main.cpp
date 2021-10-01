#include <iostream>
#include <string>
#include <vector>
#include "classes/roster.h"
#include "classes/person.h"
#include "classes/adult.h"
#include "classes/child.h"
#include "classes/events.h"
#include "functions/addingPerson.h"

using namespace std;

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

    // list of people
    vector<person*> people;

    int ammount = 0;

    int choice = 0;

    while(inProgram){
        // MAIN MENU
        mainMenu = true;
        while(mainMenu){

            cout << endl;
            cout << "+------------------------------------------------------+" << endl;
            cout << "|                      Main Menu                       |" << endl;
            cout << "+------------------------------------------------------+" << endl;
            cout << endl;

            cout << "1 - Add a new person" << endl;
            cout << "2 - View all the people" << endl;
            cout << "3 - Create a roster" << endl;
            cout << "4 - View roster" << endl;
            cout << "5 - Exit" << endl;

            cin >> choice;

            switch(choice){
                // adding a person the array of people
                case 1:
                    addPerson(people, &ammount);
                    break;
                case 2:
                    listAllpeople(people);
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