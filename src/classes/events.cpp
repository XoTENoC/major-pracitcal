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
#include "adult.h"
#include "adult.h"


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


    // variable to rand select a peson
    int personSelect;

    // finding the leader
    bool active = true;

    // making a place holder person to fillin any gaps
    person * notValid;
    notValid = new adult("No Valid Peson", 0);

    // array of people to pick from using Numberic
    vector<int> peopleLeft((int)people.size());
    iota(peopleLeft.begin(), peopleLeft.end(), 0);

    while(active == true){

        // picking a random person
        personSelect = peopleLeft[rand() % peopleLeft.size()];
        bool canBeLeader = true;

        // checking that the person can do everything
        for(int i = 0; i < 3; i++){
            if (people[personSelect]->getCompetency(i) != 2){
                canBeLeader = false;
            }
        }

        // setting the leader of ther event
        if(canBeLeader == true){
            rosterOfPeople[0] = people[personSelect];
            // cout << rosterOfPeople[0]->getPersonName() << endl; // Print the team lead ofter found
            active = false;
        }
    }

    // looping for each person in the array

    if (numberOfStaffNeeded == 4)
    {
        for(int i = 1; i < numberOfStaffNeeded; i++){

            bool foundPerson = false;
            
            // generating the list of people that are left
            vector<int> tempPeople;
            for(int k = 0; k < (int)peopleLeft.size(); k++){
                tempPeople.push_back(peopleLeft[k]);
            }


            while (foundPerson == false)
            {

                // generate the number & remove
                personSelect = tempPeople[rand() % tempPeople.size()];
                tempPeople.erase(remove(tempPeople.begin(), tempPeople.end(), personSelect), tempPeople.end());
                
                // testing
                // for ( int k = 0; k < (int)tempPeople.size(); k++){
                //     cout << tempPeople[k] << endl;
                // }
                
                switch (i)
                {

                // sound person
                case 1:
                    /* code */
                    // make sure that people with compentecy 2 get picked
                    if (!tempPeople.empty())
                    {
                        if(people[personSelect]->getCompetency(0) == 2){
                            // asigning the person to the role
                            rosterOfPeople[i] = people[personSelect];
                            // removing them from the list of people
                            peopleLeft.erase(remove(peopleLeft.begin(), peopleLeft.end(), personSelect), peopleLeft.end());
                            // going to the next person
                            foundPerson = true;
                        }
                    }
                    else 
                    {
                        rosterOfPeople[i] = new adult("No Person Found", 0);
                    }
                    break;

                // lighting Person
                case 2:
                    // make sure that people with compentecy 2 get picked
                    if (!tempPeople.empty())
                    {
                        if(people[personSelect]->getCompetency(1) == 2){
                            // asigning the person to the role
                            rosterOfPeople[i] = people[personSelect];
                            // removing them from the list of people
                            peopleLeft.erase(remove(peopleLeft.begin(), peopleLeft.end(), personSelect), peopleLeft.end());
                            // going to the next person
                            foundPerson = true;
                        }
                    }
                    else 
                    {
                        rosterOfPeople[i] = new adult("No Person Found", 0);
                    }
                    break;

                // Computer Graphics Person
                case 3:
                    // make sure that people with compentecy 2 get picked
                    if (tempPeople.empty()==0)
                    {
                        if(people[personSelect]->getCompetency(2) == 1){
                            // asigning the person to the role
                            rosterOfPeople[i] = people[personSelect];
                            // removing them from the list of people
                            peopleLeft.erase(remove(peopleLeft.begin(), peopleLeft.end(), personSelect), peopleLeft.end());
                            // going to the next person
                            foundPerson = true;
                        }
                    }
                    else 
                    {
                        // madd errors here
                        // rosterOfPeople[i] = nullptr;
                        // cout << "make all" << endl;
                        // rosterOfPeople[i] = people[1];
                        // cout << "make all" << endl;
                    }
                    break;

                default:
                    break;
                }
            }

            // clearing the array so that it can start again
            tempPeople.erase(tempPeople.begin(), tempPeople.end());
        }
    }
    else if (numberOfStaffNeeded == 7)
    {
        // for(int i = 1; i < numberOfStaffNeeded; i++){

        //     bool foundPerson = false;

        //     // list of all the people that are left
        //     vector<int> tempPeople;
        //     for(int k = 0; k < (int)peopleLeft.size(); k++){
        //         tempPeople.push_back(peopleLeft[k]);
        //     }

        //     while (foundPerson == false)
        //     {
        //         // generate the number
        //         // generate the number & remove
        //         personSelect = tempPeople[rand() % tempPeople.size()];
        //         tempPeople.erase(remove(tempPeople.begin(), tempPeople.end(), personSelect), tempPeople.end());

        //         switch (i)
        //         {

        //         // sound person
        //         case 1:
        //             rosterOfPeople[i] = people[1];
        //             cout << personSelect << endl;
        //             foundPerson = true;
        //             break;

        //         // lighting Person
        //         case 2:
        //             rosterOfPeople[i] = people[1];
        //             cout << personSelect << endl;
        //             foundPerson = true;
        //             break;

        //         // Computer Graphics Person
        //         case 3:
        //             rosterOfPeople[i] = people[1];
        //             cout << personSelect << endl;
        //             foundPerson = true;
        //             break;
                
        //         // Sound Training
        //         case 4:
        //             rosterOfPeople[i] = people[1];
        //             cout << personSelect << endl;
        //             foundPerson = true;
        //             break;

        //         // Lighting Training
        //         case 5:
        //             rosterOfPeople[i] = people[1];
        //             cout << personSelect << endl;
        //             foundPerson = true;
        //             break;

        //         // Computer Graphics Training
        //         case 6:
        //             rosterOfPeople[i] = people[1];
        //             cout << personSelect << endl;
        //             foundPerson = true;
        //             break;

        //         default:
        //             break;
        //         }
        //     }
            
        //     // clearing the array so that it can start again
        //     tempPeople.erase(tempPeople.begin(), tempPeople.end());

        // }
    }

}

events::~events(){
    delete[] rosterOfPeople;
}