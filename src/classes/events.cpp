// The file describes the functions for the events class, it definds how the
// class will function.

#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <stdlib.h>
#include <algorithm>
#include "events.h"
#include "person.h"


using namespace std;

events::events(){
    numberOfStaffNeeded = 0;
    eventName = "?";
    weekNumber = 0;
}

events::events(int numberOfStaff, string name, int number){
    numberOfStaffNeeded = numberOfStaff;
    eventName = name;
    weekNumber = number;

    rosterOfPeople = new person*[numberOfStaffNeeded];

}

int events::getNumberOfStaffNeeded(){
    return numberOfStaffNeeded;
}

void events::setNumberOfStaffNeeded(int numberOfStaff){
    numberOfStaffNeeded = numberOfStaff;
}

int events::getWeekNumber(){
    return weekNumber;
}

void events::setWeekNumber(int number){
    weekNumber = number;
}

string events::getEventName(){
    return eventName;
}

void events::setEventName(string name){
    eventName = name;
}


// Function for creating a roster for the week
void events::addRosteredPeople(vector<person*> people){
    
    int ammountOfPeople = (int)people.size();

    // variable to rand select a peson
    int personSelect;

    // finding the leader
    bool active = true;

    while(active == true){

        // picking a random person
        personSelect = rand() % ammountOfPeople + 1;
        bool canBeLeader = true;

        // checking that the person can do everything
        for(int i = 0; i < 3; i++){
            if (people[personSelect-1]->getCompetency(i) != 2){
                canBeLeader = false;
            }
        }

        // setting the leader of ther event
        if(canBeLeader == true){
            rosterOfPeople[0] = people[personSelect-1];
            active = false;
        }
    }

    // array of people to pick from using Numberic
    vector<int> peopleLeft((int)people.size());
    iota(peopleLeft.begin(), peopleLeft.end(), 0);

    // looping for each person in the array

    if (numberOfStaffNeeded == 4)
    {
        for(int i = 1; i < numberOfStaffNeeded; i++){

            bool foundPerson = false;
            
            vector<int> tempPeople;
            tempPeople = peopleLeft;

            while (foundPerson == false)
            {

                // generate the number & remove
                personSelect = tempPeople[rand() % tempPeople.size()];
                tempPeople.erase(remove(tempPeople.begin(), tempPeople.end(), personSelect), tempPeople.end());
                
                switch (i)
                {

                // sound person
                case 1:
                    /* code */
                    if(people[personSelect]->getCompetency(0) == 2){
                        rosterOfPeople[i] = people[personSelect];
                        peopleLeft.erase(remove(peopleLeft.begin(), peopleLeft.end(), personSelect), peopleLeft.end());
                        foundPerson = true;
                    }
                    break;

                // lighting Person
                case 2:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;

                // Computer Graphics Person
                case 3:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;

                default:
                    break;
                }
            }

        }
    }
    else if (numberOfStaffNeeded == 7)
    {
        for(int i = 1; i < numberOfStaffNeeded; i++){

            bool foundPerson = false;

            while (foundPerson == false)
            {
                // generate the number
                personSelect = rand() % ammountOfPeople + 1;

                switch (i)
                {

                // sound person
                case 1:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;

                // lighting Person
                case 2:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;

                // Computer Graphics Person
                case 3:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;
                
                // Sound Training
                case 4:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;

                // Lighting Training
                case 5:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;

                // Computer Graphics Training
                case 6:
                    rosterOfPeople[i] = people[1];
                    foundPerson = true;
                    break;

                default:
                    break;
                }
            }
            

        }
    }

}

events::~events(){
    delete[] rosterOfPeople;
}