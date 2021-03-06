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

bool events::addingPersonToList(int number, int personSelect, vector<int> &peopleLeft, vector<person*> people){
    // asigning the person to the role
    rosterOfPeople[number] = people[personSelect];
    // removing them from the list of people
    peopleLeft.erase(remove(peopleLeft.begin(), peopleLeft.end(), personSelect), peopleLeft.end());
    // going to the next person
    return true;
}

// Function for creating a roster for the week
void events::addRosteredPeople(vector<person*> people){


    // variable to rand select a peson
    int personSelect;

    // finding the leader
    bool active = true;

    // array of people to pick from using Numberic
    vector<int> peopleLeft((int)people.size());
    iota(peopleLeft.begin(), peopleLeft.end(), 0);

    vector<int> tempPeople;
    for(int k = 0; k < (int)peopleLeft.size(); k++){
        tempPeople.push_back(peopleLeft[k]);
    }

    while(active == true){

        // picking a random person
        personSelect = peopleLeft[rand() % peopleLeft.size()];
        bool canBeLeader = true;

        tempPeople.erase(remove(tempPeople.begin(), tempPeople.end(), personSelect), tempPeople.end());
        
        int age = people[personSelect]->getAge();

        
        if (age >= 18){
            // checking that the person can do everything
            for(int i = 0; i < 3; i++){
                if (people[personSelect]->getCompetency(i) != 2){
                    canBeLeader = false;
                }
            }

            // setting the leader of ther event
            if(canBeLeader == true){
                rosterOfPeople[0] = people[personSelect];
                // cout << rosterOfPeople[0]->getPersonName() << endl; // Print the team    lead ofter found
                active = false;
            }

            // if no leader can be found it will exit the program
            if(tempPeople.empty()){
                cout << "no leader can't be found" << endl;
                rosterOfPeople[0] = new adult("No Person Found", 0);
                return;
            }
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

                if (!tempPeople.empty())
                {
                    if(people[personSelect]->getCompetency(i-1) == 2){
                        foundPerson = addingPersonToList(i, personSelect, peopleLeft, people);
                    }
                }
                else 
                {
                    rosterOfPeople[i] = new adult("No Person Found", 0);
                    foundPerson = true;
                }
                
            }

            // clearing the array so that it can start again if there are still
            // values in the array
            if (tempPeople.empty()==0){
                tempPeople.erase(tempPeople.begin(), tempPeople.end());
            }
        }

    }
    // rostering for a team of 7 people
    else if (numberOfStaffNeeded == 7)
    {
        for(int i = 0; i < numberOfStaffNeeded - 1; i++){

            bool foundPerson = false;
            int competencies[6] = {1, 3, 5, 2, 4, 6};
            int competenciesPos[6] = {0, 1, 2, 0, 1, 2};

            // list of all the people that are left
            vector<int> tempPeople;
            for(int k = 0; k < (int)peopleLeft.size(); k++){
                tempPeople.push_back(peopleLeft[k]);
            }

            while (foundPerson == false)
            {
                // generate the number
                // generate the number & remove
                personSelect = tempPeople[rand() % tempPeople.size()];
                tempPeople.erase(remove(tempPeople.begin(), tempPeople.end(), personSelect), tempPeople.end());

                // adding the person to the roster
                if (tempPeople.empty()==0)
                {
                    if(people[personSelect]->getCompetency(competenciesPos[i]) == 2){
                        foundPerson = addingPersonToList(competencies[i], personSelect, peopleLeft, people);
                    }
                }
                else 
                {
                    // madd errors here
                    rosterOfPeople[competencies[i]] = new adult("No Person Found", 0);
                    foundPerson = true;
                }

            }
            
            // clearing the array so that it can start again if there are still
            // values in the array
            if (tempPeople.empty()==0){
                tempPeople.erase(tempPeople.begin(), tempPeople.end());
            }

        }
    }

}

events::~events(){
    delete[] rosterOfPeople;
}