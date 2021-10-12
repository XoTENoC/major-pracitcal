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

    // Gets the number of the events
    int numberOfEvents = (int)allEvents.size();

    // for all the events
    for (int i = 0; i < numberOfEvents; i++){

        // getting the number of the people in the roster
        int numberOfPeople = allEvents[i]->getNumberOfStaffNeeded();

        // printing out all the people
        for (int j = 0; j < numberOfPeople; j++){
            cout << allEvents[i]->rosterOfPeople[j]->getPersonName() << " ";
        }

        // printing the new line
        cout << endl;

    }

}