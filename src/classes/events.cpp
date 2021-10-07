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

void events::addRosteredPeople(vector<person*> people){

    cout<<endl<<"working"<<endl;
}

events::~events(){
    delete[] rosterOfPeople;
}