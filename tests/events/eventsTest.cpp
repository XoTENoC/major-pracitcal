#include <string>
#include <iostream>
#include <vector>
#include "../../src/classes/person.h"
#include "../../src/classes/adult.h"
#include "../../src/classes/child.h"
#include "../../src/classes/events.h"
#include "../../src/functions/addingPerson.h"
#include "../../src/functions/addingRoster.h"
#include "../../src/functions/viewRoster.h"
#include "../../src/functions/inputValidation.h"

using namespace std;

int main(){

    // clearing the screen
    system("clear");

    // printing the title of the program
    // Starting the program
    bool inProgram = true;
    bool mainMenu = true;

    // list of people
    vector<person*> people;
    vector<events*> allEvents;

    // setting all the test data

    // init variables
    int amount = 0;
    int choice = 0;
    int choices[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    while(inProgram){
        
        // MAIN MENU
        mainMenu = true;
        while(mainMenu){

            cout << endl;
            cout << "+------------------------------------------------------+" << endl;
            cout << "|                      Main Menu                       |" << endl;
            cout << "+------------------------------------------------------+" << endl;
            cout << endl;

            cout << "1 - Add/modify a person" << endl;
            cout << "2 - Remove a person" << endl;
            cout << "3 - View all the people" << endl;
            cout << "4 - Get Contacts" << endl;
            cout << "5 - Add An Event" << endl;
            cout << "6 - Remove an event" << endl;
            cout << "7 - View roster" << endl;
            cout << "8 - Exit" << endl;

            choice = inputNumStatic(choices, 8);

            switch(choice){
                // adding a person the array of people
                case 1:
                    addPerson(people, &amount);
                    break;
                case 2:
                    removePerson(people);
                    break;
                case 3:
                    listAllpeople(people);
                    break;
                case 4:
                    getContacts(people);
                    break;
                case 5:
                    addEvent(allEvents, people);
                    break;
                case 6:
                    removeEvent(allEvents);
                    break;
                case 7:
                    displayRoster(allEvents);
                    break;
                case 8:
                    mainMenu = false;
                    inProgram = false;
                    break;
            }
        }

    }
}