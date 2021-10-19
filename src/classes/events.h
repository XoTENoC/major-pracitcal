// This class is defined for each week of the roster, this houses all the
// people within the week. It holds the event name, what week of the roster it
// is and how many people are on the roster for that week

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
        
        int getNumberOfStaffNeeded();
        void setNumberOfStaffNeeded(int numberOfStaff);

        int getWeekNumber();
        void setWeekNumber(int number);

        void addRosteredPeople(vector<person*> people);

        string getEventName();
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