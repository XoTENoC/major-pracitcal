// The file discribes the functions for the events class, it definds how the
// class will function.

#include <string>
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
}

int events::getWeekNumber(){
    return weekNumber;
}

void events::setWeekNumber(int number){
    weekNumber = number;
}

string getEventName(){
    return eventName;
}

void setWeekNumber(string name){
    eventName = name;
}