// The file describes the functions for the events class, it definds how the
// class will function.

#include <string>
#include<iostream>
#include<vector>
#include <stdlib.h>
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

    // looping for each person in the array

    if (numberOfStaffNeeded == 4)
    {
        for(int i = 1; i < numberOfStaffNeeded; i++){

            bool foundPerson = false;

            while (foundPerson = flase)
            {
                // generate the number
                personSelect = rand() % ammountOfPeople + 1;

                switch (i)
                {

                // sound person
                case 1:
                    /* code */
                    break;

                // lighting Person
                case 2:
                    /* code */
                    break;

                // Computer Graphics Person
                case 3:
                    /* code */
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

            while (foundPerson = flase)
            {
                // generate the number
                personSelect = rand() % ammountOfPeople + 1;

                switch (i)
                {

                // sound person
                case 1:
                    /* code */
                    break;

                // lighting Person
                case 2:
                    /* code */
                    break;

                // Computer Graphics Person
                case 3:
                    /* code */
                    break;
                
                // Sound Training
                case 4:
                    /* code */
                    break;

                // Lighting Training
                case 5:
                    /* code */
                    break;

                // Computer Graphics Training
                case 6:
                    /* code */
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