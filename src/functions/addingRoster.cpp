#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/roster.h"
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"

void createRoster(vector<person*> people, int numberOfStaffTotal){
        int numWeeks=0;
        cout<<"Please input the number of weeks to be created:";
        cin>>numWeeks;
        cout<<endl; 
        roster *newRoster = new roster(numWeeks);

        for(int i=0;i<numWeeks;i++){
        string thisEventName; 
        cout<< "Please enter the name for event "<< i+1<<":";
        cin >>thisEventName;
        cout<<endl; 
        int numPeopleRequired =0;

        cout<< "Please enter the number of people required for the event: ";
        cin>> numPeopleRequired;
        cout<<endl; 
        person thesePeople[numPeopleRequired]; 
        events *newEvent = new events(numPeopleRequired,thesePeople,thisEventName,i);
        newEvent->addRosteredPeople(people);

        int thisNumStaff = newEvent->numberOfStaffNeeded;

        cout<<"event added"<<endl;


        }
}