/* 

event.h

This class is defined for each week of the roster, this houses all the
people within the week. It holds the event name, what week of the roster it
is and how many people are on the roster for that week

*/

#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include<vector>

#include "person.h"

using namespace std;

class events{
    public:
        // Variable within the week.
        // this is the roster of people for the event.
        person ** rosterOfPeople;


        //functions of the class
        events();
        events(int numberOfStaff, string name, int number);
        
        // returns an int of the number of staff needed for the event
        int getNumberOfStaffNeeded();
        // takes in the int input of either 4 or 7 and stores in the variable of
        // numberOfStaff for creating the roster
        void setNumberOfStaffNeeded(int numberOfStaff);

        // returns the week number of the event
        int getWeekNumber();
        // takes in the int of a week number and stores in varuiable weekNumber
        void setWeekNumber(int number);

        // creates the roster for the event, by passing in a vector of perople
        void addRosteredPeople(vector<person*> people);

        // returns the event name
        string getEventName();
        // takes in a string of any length and stores that in the variable of
        // eventName.
        void setEventName(string name);

        // add a function to make a person

        ~events();

    private:
        string eventName;
        int weekNumber;     
        int numberOfStaffNeeded;

        bool addingPersonToList(int number, int personSelect, vector<int> &peopleLeft, vector<person*> people);
   
};

#endif //  EVENTS_H