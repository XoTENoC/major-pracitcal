#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"


using namespace std;

void outputCsv(vector<events*> allEvents){

    string positionsArray3[7] = {"Team Lead","Sound","Lighting","CG", "Trainee Sound","Trainee Lighting",  "Trainee CG"};

    std::ofstream rosterCSV("roster.csv");
    rosterCSV<<"Event Name, Position, Staff Member \n";
    for(int j=0;j<(int)allEvents.size();j++){
        int numberOfPeople = allEvents[j]->getNumberOfStaffNeeded();

    for(int i=0;i<numberOfPeople;i++){
        rosterCSV<<allEvents[j]->eventName<<","<<positionsArray3[i]<<","<<allEvents[j]->rosterOfPeople[i]->getPersonName()<<"\n";
    }
    }

}


void displayRoster(vector<events*> allEvents){
    

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                    View Roster                       |" << endl;
    cout << "+------------------------------------------------------+" << endl;   
    cout<<endl;
     // Gets the number of the events
    int numberOfEvents = (int)allEvents.size();
    
    //defines the meaning of array positions
    string positionsArray3[7] = {"Team Lead       ","Sound           ","Lighting        ","CG              ", "Trainee Sound   ","Trainee Lighting",  "Trainee CG      "};


    // for all the events
    for (int i = 0; i < numberOfEvents; i++){

        // getting the number of the people in the roster
        int numberOfPeople = allEvents[i]->getNumberOfStaffNeeded();
        // printing out all the people


    //print event name, centering in box
    int numberOfSpaces =( 54- allEvents[i]->eventName.length() )/2;

    cout << "+------------------------------------------------------+" << endl;
    cout << "+";

    for(int s =0;s<numberOfSpaces;s++){
        cout<<" ";
    }

    cout<< allEvents[i]->eventName;
    if(allEvents[i]->eventName.length()%2==0){
    for(int s =0;s<numberOfSpaces;s++){
        cout<<" ";
    }
    }
    else{
        for(int s =0;s<numberOfSpaces+1;s++){
        cout<<" ";
    }
    }

    cout << "+";

    cout<<endl; 
        if(numberOfPeople<8){
        for (int j = 0; j < numberOfPeople; j++){
            cout << "+------------------------------------------------------+" << endl;
            cout << "| "<<positionsArray3[j]<<"  | "<< allEvents[i]->rosterOfPeople[j]->getPersonName()<<"                           |" << endl;
        }
        }
        else{
            for (int j = 0; j < 7; j++){
            cout << "+------------------------------------------------------+" << endl;
            cout << "| "<<positionsArray3[j]<<"  | "<< allEvents[i]->rosterOfPeople[j]->getPersonName()<<"                           |" << endl;
        }
            for(int l = 7;l<numberOfPeople;l++){
            cout << "+------------------------------------------------------+" << endl;
            cout << "| "<<"Undefined Role  "<<"  | "<< allEvents[i]->rosterOfPeople[l]->getPersonName()<<"                           |" << endl;

            }
        }

        // printing the new line
        cout << "+------------------------------------------------------+" << endl;
    
    
    }

    outputCsv(allEvents);
}