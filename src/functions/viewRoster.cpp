#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"

using namespace std;

void displayRoster(vector<events*> allEvents){
    

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                    View Roster                       |" << endl;
    cout << "+------------------------------------------------------+" << endl;   
    cout<<endl;
     // Gets the number of the events
    int numberOfEvents = (int)allEvents.size();
    
    //defines the meaning of array positions
    string positionsArray3[7] = {"Team Lead       ","Sound           ","Lighting        ","CG              ", "Trainee Sound   ","Trainee Lighting",  "Trainee CG      "};


    // for all the events
    for (int i = 0; i < numberOfEvents; i++){

        // getting the number of the people in the roster
        int numberOfPeople = allEvents[i]->getNumberOfStaffNeeded();
        // printing out all the people

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                    Week "<<i+1<<"                            |" << endl;
 
            


        for (int j = 0; j < numberOfPeople; j++){
            cout << "+------------------------------------------------------+" << endl;
            cout << "| "<<positionsArray3[j]<<"  | "<< allEvents[i]->rosterOfPeople[j]->getPersonName()<<"                           |" << endl;
           // cout << allEvents[i]->rosterOfPeople[j]->getPersonName() << " ";
        }

        // printing the new line
        cout << "+------------------------------------------------------+" << endl;

    
    }
}