#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"


void addEvent(vector < person * > people, vector < events * > allEvents) {

  int numberOfEvents = 0;
  int * ptrNumEvents = & numberOfEvents;
  bool isComplete = false;
  while (isComplete != true) {

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                         Events                       |" << endl;
    cout << "+------------------------------------------------------+" << endl;

    int choice;
    cout << "1 - Add a new event" << endl <<
      "2 - Exit" << endl;
    cin >> choice;

    switch (choice) {
      // adding a person the array of people
    case 1:
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