#include <iostream>
#include <string.h>
#include "roster.h"
#include "person.h"
#include "adult.h"
#include "child.h"
#include "events.h"

using namespace std;

void addPerson(person * arr, int * ammount){
    person * tempArrayOfPerople;
    int option = 0;
    bool isTrue = true;
    string name;
    int age, competency;

    // picking whether you are adding a Adult or Child
    while(isTrue){
        cout << "1 - To add an Adult" << endl;
        cout << "2 - To add a Child" << endl;
        cout << "3 - bail" << endl;
        cin >> option;

        switch (option){
            case 1:
                isTrue = false;
                // creating a new array person
                tempArrayOfPerople = new person[*ammount];

                for (int i = 0; i < *ammount; i++){
                    arr[i] = tempArrayOfPerople[i];
                }

                delete[] arr;
                // id of people incease
                *ammount++;
                arr = new person[*ammount]; 

                for (int i = 0; i < *ammount-1; i++){
                    tempArrayOfPerople[i] = arr[i];
                }

                delete[] tempArrayOfPerople;
                
                cout << "name for the person: ";
                cin >> name;

                cout << "Age of the person: ";
                cin >> age;

                arr[*ammount] = adult(name, age);

                cout << "ability of sound: ";
                cin >> competency;

                arr[*ammount].setCompetency(0, competency);

                cout << "ability of lighting: ";
                cin >> competency;

                arr[*ammount].setCompetency(1, competency);

                cout << "ability of computer graphics: ";
                cin >> competency;

                arr[*ammount].setCompetency(2, competency);

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

int main(){
    bool inProgram = true;
    bool mainMenu = true;

    // keeping a track of all the people created
    int numberOfPeople = 0;
    person * arrayOfPeople;

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
                    addPerson(arrayOfPeople, &numberOfPeople);
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