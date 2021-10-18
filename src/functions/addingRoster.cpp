#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"
#include "inputValidation.h"

using namespace std;

// adding a new event to the array
void addingNewEvent(vector < events * > &allEvents){

	int numberOfStaff;
	string nameOfEvent;
  int staffNumbers[2] = {4, 7};

	// asking for the number of Staff
	cout << "how many staff are needed for the event (either 4 or 7): ";
	numberOfStaff = inputNumStatic(staffNumbers, 2);

	// asking for the name of the event
	cout << "What is the name of event: ";
	nameOfEvent = intputStringAmmount(25);

	// adds the events to the array
	allEvents.push_back(new events(numberOfStaff, nameOfEvent, 0));

}

void removeEvent(vector <events*> &allEvents){
	int index;

	cout << "What index would you like to remove?: ";
	cin >> index;

	cout << "Removing " << allEvents[index-1]->getEventName() << endl;

	allEvents.erase(allEvents.begin()+(index-1));

}

void rosteringPeople(vector<events*> &allEvents, vector<person*> allPeople){

	// finding the lasts event
	int lastEvent = (int)allEvents.size() - 1;

	// rostering people
	allEvents[lastEvent]->addRosteredPeople(allPeople);

}


void addEvent(vector<events*> &allEvents, vector<person*> people) {

  
  bool isComplete = false;
  int options[2] = {1, 2};

  while (isComplete != true) {

	  // clearing the screen
	  system("clear");

    	cout << "+------------------------------------------------------+" << endl;
    	cout << "|                         Events                       |" << endl;
    	cout << "+------------------------------------------------------+" << endl;

    	int choice;
    	cout << "1 - Add a new event" << endl;
    	cout << "2 - Exit" << endl;
    	choice = inputNumStatic(options, 2);

    	switch (choice) {
    	// adding a person the array of people
    	case 1:
    		addingNewEvent(allEvents);
			rosteringPeople(allEvents, people);
    	  	break;
    	case 2:
    	  	isComplete = true;
    	  	break;
    	}
  	}
}
