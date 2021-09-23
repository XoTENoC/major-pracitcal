#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include "person.h"
#include "adult.h"
#include "child.h"

using namespace std;

class events{
    public:
        int numberOfStaffNeeded;
        person* rosterOfPeople;
        string eventName;
        int weelNumber;
};

#endif //  EVENTS_H