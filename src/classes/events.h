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
        int numberOfStaffNeeded;
        person* rosterOfPeople;
        string eventName;
        int weekNumber;

        //functions of the class
        events();
        events(int numberOfStaff, person* roster, string name, int number);
        
        int getNumberOfStaffNeeded();
        void setNumberOfStaffNeeded(int numberOfStaff);

        int getWeekNumber();
        void setWeekNumber(int number);

        void addRosteredPeople(vector<person*> people, int numberOfTotalStaff);

        string getEventName();
        void setEventName(string name);

        ~events();
};

#endif //  EVENTS_H