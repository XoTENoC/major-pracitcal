#include <string>
#include "roster.h"
#include "person.h"
#include "events.h"

roster::roster(){
    rosterArray = nullptr;
    numberOfEvents = 0;
}

roster::roster(int eventsAmmount){
    numberOfEvents = eventsAmmount;
    rosterArray = new events[numberOfEvents];
}

int roster::getNumberOfEvents(){
    return numberOfEvents;
}

int roster::setNumberOfEvents(int eventsAmmount){
    numberOfEvents = eventsAmmount;
}

roster::~roster(){
    delete[] rosterArray;
}

