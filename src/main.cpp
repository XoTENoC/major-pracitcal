#include <iostream>
#include <string>
#include "roster.h"
#include "person.h"
#include "adult.h"
#include "child.h"
#include "events.h"

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
                // creating a new array person

                // checking to make sure that there are already people in the
                // array
                if(*ammount>0){

                    // starting the temp array to store people
                    tempArrayOfPerople = new person*[size];
                    cout << "created temp array" << endl;

                    // moving all there perople into the array
                    for (int i = 0; i < *ammount; i++){
                        arr[i] = tempArrayOfPerople[i];
                        cout << i << endl;
                    }

                    cout << "Made it" << endl;

                    // Should be Deleting the array but causing a segmentation fault
                    // delete[] arr;

                    cout << "Made it" << endl;

                    // id of people incease
                    *ammount += 1;

                    cout << "Made it" << endl;

                    // making the array one person bigger
                    arr = new person*[*ammount];

                    cout << "Made it" << endl;

                    // Asking for the name
                    cout << "name for the person: ";
                    cin >> name;

                    // Asking for the age
                    cout << "Age of the person: ";
                    cin >> age;

                    arr[*ammount-1] = new adult(name, age);

                    cout << arr[*ammount-1]->getPersonName() << endl;

                    // moving people into the new array
                    for (int i = 0; i < *ammount-1; i++){
                        tempArrayOfPerople[i] = arr[i];
                    }
                    
                    // Deleting the temp array
                    delete[] tempArrayOfPerople;
                }
                
                // if there are no people in the array make the array 1.
                else if( *ammount == 0 ){
                    arr = new person*[1];
                    *ammount += 1;

                    // Asking for the name
                    cout << "name for the person: ";
                    cin >> name;

                    // Asking for the age
                    cout << "Age of the person: ";
                    cin >> age;

                    arr[*ammount-1] = new adult(name, age);

                    cout << arr[0]->getPersonName() << endl;
                }

                // // assigning all the competencies of the person
                // cout << "ability of sound: ";
                // cin >> competency;

                // arr[*ammount]->setCompetency(0, competency);

                // cout << "ability of lighting: ";
                // cin >> competency;

                // arr[*ammount]->setCompetency(1, competency);

                // cout << "ability of computer graphics: ";
                // cin >> competency;

                // arr[*ammount]->setCompetency(2, competency);

                break;
            case 2:
                isTrue = false;

                // // creating a new array person

                // // checking to make sure that there are already people in the
                // // array
                // if(*ammount>0){

                //     // starting the temp array to store people
                //     tempArrayOfPerople = new person[*ammount];

                //     // moving all there perople into the array
                //     for (int i = 0; i < *ammount; i++){
                //         arr[i] = tempArrayOfPerople[i];
                //     }

                //     // making room for the next array
                //     delete[] arr;

                //     // id of people incease
                //     *ammount += 1;

                //     // making the array one person bigger
                //     arr = new person[*ammount]; 

                //     // moving people into the new array
                //     for (int i = 0; i < *ammount-1; i++){
                //         tempArrayOfPerople[i] = arr[i];
                //     }
                    
                //     // Deleting the temp array
                //     delete[] tempArrayOfPerople;
                // }

                // // if there are no people in the array make the array 1.
                // else if( *ammount == 0 ){
                //     delete[] arr;
                //     arr = new person[1];
                //     *ammount += 1;
                // }

                // // Asking for the name
                // cout << "name for the person: ";
                // cin >> name;

                // // Asking for the age
                // cout << "Age of the person: ";
                // cin >> age;

                // // assinging the name and the age
                // newChild.setPersonName(name);
                // newChild.setAge(age);

                // // assigning the person to the array in the last spot
                // arr[*ammount] = newChild;

                // // assigning all the competencies of the person
                // cout << "ability of sound: ";
                // cin >> competency;

                // arr[*ammount].setCompetency(0, competency);

                // cout << "ability of lighting: ";
                // cin >> competency;

                // arr[*ammount].setCompetency(1, competency);

                // cout << "ability of computer graphics: ";
                // cin >> competency;

                // arr[*ammount].setCompetency(2, competency);

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
    bool inProgram = true;
    bool mainMenu = true;

    // keeping a track of all the people created
    int numberOfPeople = 0;
    person ** arrayOfPeople;

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
                    viewAllPeople(arrayOfPeople, &numberOfPeople);
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