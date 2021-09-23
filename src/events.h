#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include "person.h"

using namespace std;

// This class is defined for each week of the rooster, this houses all the
// people within the week. It holds the event name, what week of the roster it
// is and how many people are on the roster for that week

class events{
    public:
        // Variable within the week.
        int numberOfStaffNeeded;
        person* rosterOfPeople;
        string eventName;
        int weekNumber;

        //functions of the class
        events();
        events(int numberOfStaffNeeded, person* rosterOfPeople, string eventName, int weekNumber);
        
        int getNumberOfStaffNeeded();
        void setNumberOfStaffNeeded(int numberOfStaff);

        int getWeekNumber();
        void setWeekNumber(int weekNumber);

        string getEventName();
        void setEventName();

        ~events();
};

#endif //  EVENTS_H