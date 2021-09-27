#include <iostream>
#include <string.h>
#include "roster.h"
#include "person.h"
#include "events.h"

using namespace std;

void addPerson(person * arr, person * arrTemp, int * ammount){


}

int main(){
    bool inProgram = true;
    bool mainMenu = true;

    // keeping a track of all the people created
    int numberOfPeople = 0;
    person * arrayOfPeople;
    person * tempArrayOfPerople;

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
                    addPerson(arrayOfPeople, tempArrayOfPerople, &numberOfPeople);
                    break;
                case 2:
                    mainMenu = false;
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