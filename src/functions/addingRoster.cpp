#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
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
	
	// clearing the screen
	system("clear");

	cout << "+------------------------------------------------------+" << endl;
    cout << "|                     List of Events                   |" << endl;
    cout << "+------------------------------------------------------+" << endl;

	cout << endl;

	// printing all the event names
	for (int i = 0; i < (int)allEvents.size(); i++){
		cout << i + 1 << ": " << allEvents[i]->getEventName() << endl;
	}

	cout << endl;

	int index;

	// creating an array with all the event positions for input validation
	vector<int> numberOfEvents((int)allEvents.size());
    iota(numberOfEvents.begin(), numberOfEvents.end(), 1);
	int * dataNumberOfEvents = numberOfEvents.data();

	// makeing sure that there are events
	if ((int)allEvents.size() !=0){
		cout << "What index would you like to remove?: ";
		// making sure that the user can only add what they need to
		index = inputNumStatic(dataNumberOfEvents, (int)allEvents.size());
	}
	else
	{
		// if there is no one in the array wait for the user to continue
		cout << "There are no Events, press enter to continue" << endl;
		cin.get();
		cin.ignore();
		return;
	}

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
