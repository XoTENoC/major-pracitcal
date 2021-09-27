#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "person.h"
#include "events.h"

using namespace std;

class roster{
    public:

    roster();
    roster(int eventsAmmount);

    // if needed in the future more positions can be added with a function.
    string positions[4] = {"Team Leader", "Sound", "Lighting", "Computer Graphics"};
    int numberOfNeeededPositions = 4;
    int numberOfPossiblePossitions = numberOfNeeededPositions + (numberOfNeeededPositions - 1);
    int numberOfEvents;
    events * rosterArray;

    int getNumberOfEvents();
    int setNumberOfEvents(int eventsAmmount);
    
};

#endif