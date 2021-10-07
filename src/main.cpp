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

//Sophie's code - not working as vector people array has been changed from a standard array! Hence the constructor doesn't work. 
void createRoster(vector<person*> people, int numberOfStaffTotal){
        int numWeeks=0;
        cout<<"Please input the number of weeks to be created:";
        cin>>numWeeks;
        cout<<endl; 
        roster *newRoster = new roster(numWeeks);

        for(int i=0;i<numWeeks;i++){
        string thisEventName; 
        cout<< "Please enter the name for event "<< i+1<<":";
        cin >>thisEventName;
        cout<<endl; 
        int numPeopleRequired =0;

        cout<< "Please enter the number of people required for the event: ";
        cin>> numPeopleRequired;
        cout<<endl; 
        person thesePeople[numPeopleRequired]; 
        events *newEvent = new events(numPeopleRequired,thesePeople,thisEventName,i);
        newEvent->addRosteredPeople(people);

        int thisNumStaff = newEvent->numberOfStaffNeeded;

        cout<<"event added"<<endl;


        }
}

int main(){

    // Starting the program
    bool inProgram = true;
    bool mainMenu = true;

    // list of people
    vector<person*> people;

    // init variables
    int amount = 0;
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
                    addPerson(people, &amount);
                    break;
                case 2:
                    listAllpeople(people);
                    break;
                case 3:
                    //mainMenu = false;
                    createRoster(people, 10);
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