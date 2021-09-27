#include <string>
#include<iostream>
#include "events.h"
#include "adult.h"
#include "child.h"


using namespace std;

int main(){


    int numStaff = 3;
    person* people = new person[3];
    adult Austen("Austen", 19);
    adult Sophie("Sophie", 19);
    child Nathiel("Nathaniel", 10); 

    people[0] = Austen;
    people[1] = Sophie;
    people[2] = Nathiel; 

    events event1(numStaff,people, "TestEvent", 1 );

    cout << event1.getEventName() << " " << event1.getNumberOfStaffNeeded() << " " << event1.getWeekNumber() << endl;

    for(int i =0; i<numStaff;i++){
        cout << event1.rosterOfPeople[i].getPersonName()<<endl;


    }

    return 0; 
}