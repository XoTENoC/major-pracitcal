#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/roster.h"
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"

events* addEvent(int *numberOfEventsPtr, vector<person *> people, int numberOfStaffTotal)
{

        string thisEventName;
        cout << "Please enter the name for event " << (*numberOfEventsPtr) + 1 << ":";
        cin >> thisEventName;
        cout << endl;
        int numPeopleRequired = 0;

        cout << "Please enter the number of people required for the event: ";
        cin >> numPeopleRequired;
        cout << endl;
        person thesePeople[numPeopleRequired];
        events *newEvent = new events(numPeopleRequired, thesePeople, thisEventName, 1);
        newEvent->addRosteredPeople(people, numberOfStaffTotal);
        (*numberOfEventsPtr)++;
        cout << "event added" << endl;
        return newEvent;
}
void createRoster(vector<person *> people, int numberOfStaffTotal)
{
        roster *newRoster = new roster(1);
        events *arrayOfEvents = new events[1]; 
        int numberOfEvents = 0;
        int *ptrNumEvents = &numberOfEvents;
        bool isComplete = false;
        while (isComplete != true)
        {

                cout << "+------------------------------------------------------+" << endl;
                cout << "|                      Add Roster                      |" << endl;
                cout << "+------------------------------------------------------+" << endl;

                int choice;
                cout << "1 - Add a new event" << endl
                     << "2 - Exit" << endl;
                cin >> choice;

                if(numberOfEvents>1){
                events *tempArray= new events[numberOfEvents];

                        for(int i=0;i<numberOfEvents-1;i++){
                                tempArray[i]= arrayOfEvents[i];
                        }
                        delete arrayOfEvents;

                        events *arrayOfEvents = new events[numberOfEvents];   
                        for(int i=0;i<numberOfEvents;i++){
                                arrayOfEvents[i]= tempArray[i];
                        }
                        delete tempArray;
                }

                switch (choice)
                {
                // adding a person the array of people
                case 1:
                        arrayOfEvents[numberOfEvents-1]= *(addEvent(ptrNumEvents, people, numberOfStaffTotal));

                        

                        break;
                case 2:
                        // cout<<"Working";
                        // newRoster->rosterArray = arrayOfEvents;

                        // cout<<newRoster->rosterArray[1].getEventName()<<"added";
                        isComplete = true;

                        break;
                }
        }
}
