// The file describes the functions for the events class, it definds how the
// class will function.

#include <string>
#include<iostream>
#include<vector>
#include "events.h"
#include "person.h"


using namespace std;

events::events(){
    numberOfStaffNeeded = 0;
    eventName = "?";
    weekNumber = 0;
}

events::events(int numberOfStaff, person* roster, string name, int number){
    numberOfStaffNeeded = numberOfStaff;
    rosterOfPeople = roster;
    eventName = name;
    weekNumber = number;
}

int events::getNumberOfStaffNeeded(){
    return numberOfStaffNeeded;
}

void events::setNumberOfStaffNeeded(int numberOfStaff){
    numberOfStaffNeeded = numberOfStaff;
    rosterOfPeople = new person[numberOfStaff];
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

void events::addRosteredPeople(vector<person*> people,int numberOfTotalStaff){
    // if(numberOfTotalStaff>3){
    // for(int i=0;i<numberOfTotalStaff;i++){

    //     int sound; 
    //     sound = people[i]->getCompetency(0);
    //     if(sound == 2){
    //         rosterOfPeople[1]= *people[i]; 
    //     }
    // }
    // for(int i=0;i<numberOfStaffNeeded;i++){
    //     int lighting;
    //     lighting = people[i]->getCompetency(1);
    //     if(lighting==2&&(people[i]->personName!=rosterOfPeople[0].personName)){
    //         rosterOfPeople[i]=*people[i];
    //     }

    // }
    // }
    // cout<<endl<<"working"<<endl;
}

events::~events(){
    delete[] rosterOfPeople;
}