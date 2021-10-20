#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"

using namespace std;

void outputCsv(vector<events *> allEvents)
{

    //define positions
    string positionsArray7[7] = {"Team Lead", "Sound", "Lighting", "CG", "Trainee Sound", "Trainee Lighting", "Trainee CG"};
    //create file
    std::ofstream rosterCSV("roster.csv");
    //name columns
    rosterCSV << "Event Name, Position, Staff Member \n";
    //loop through for each staff member, printing to the file comma seperated.
    for (int j = 0; j < (int)allEvents.size(); j++)
    {
        int numberOfPeople = allEvents[j]->getNumberOfStaffNeeded();

        for (int i = 0; i < numberOfPeople; i++)
        {
            rosterCSV << allEvents[j]->getEventName() << "," << positionsArray7[i] << "," << allEvents[j]->rosterOfPeople[i]->getPersonName() << "\n";
        }
    }
}

void getContacts(vector<person*> &vectorPeople)
{
    // clearing the screen
    system("clear");

    // DELETE AFTER TESTING.

    string* ptr;

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                 Contact Information                  |" << endl;
    cout << "+------------------------------------------------------+" << endl;

    // Gets the number of people
    int numberOfPeople = vectorPeople.size();

    for(int i=0; i<numberOfPeople; i++){
        if(vectorPeople[i]->hasContactInformation==true){
            if(vectorPeople[i]->getAge()>=18){
                cout << (vectorPeople[i]->getContactInformation())[0] << endl;
            }
            if(vectorPeople[i]->getAge()<18){
                ptr = vectorPeople[i]->getContactInformation();
                for(int j=0; j<3; j++){
                    cout << ptr[j] << endl;
                }
            }
        cout << "+------------------------------------------------------+" << endl;
        }
    }
    system("clear");
}

void displayRoster(vector<events *> allEvents)
{

    // clearing the screen
    system("clear");

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                    View Roster                       |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << endl;

    // Gets the number of the events
    int numberOfEvents = (int)allEvents.size();

    //defines the meaning of array positions for different sized teams
    string positionsArray7[7] = {"Team Lead       ", "Sound           ", "Trainee Sound   ", "Lighting        ", "Trainee Lighting", "CG              ", "Trainee CG      "};
    string positionsArray4[4] = {"Team Lead       ", "Sound           ", "Lighting        ", "CG              "};

    // for all the events
    for (int i = 0; i < numberOfEvents; i++)
    {

        // get the number of the people in the roster
        int numberOfPeople = allEvents[i]->getNumberOfStaffNeeded();

        //print event name, centering in box
        int numberOfSpaces = (54 - allEvents[i]->getEventName().length()) / 2;
        cout << "+------------------------------------------------------+" << endl;
        cout << "+";
        for (int s = 0; s < numberOfSpaces; s++)
        {
            cout << " ";
        }

        //output the event name
        cout << allEvents[i]->getEventName();

        //if even number, put half of the spaces on each side
        if (allEvents[i]->getEventName().length() % 2 == 0)
        {
            for (int s = 0; s < numberOfSpaces; s++)
            {
                cout << " ";
            }
        }

        //if odd number, add 1 more space to the right side
        else
        {
            for (int s = 0; s < numberOfSpaces + 1; s++)
            {
                cout << " ";
            }
        }
        cout << "+";
        cout << endl;

        //if there are 4 people in the team
        if (numberOfPeople == 4)
        {
            for (int j = 0; j < 4; j++)
            {
                int numberOfSpaces = 33 - allEvents[i]->rosterOfPeople[j]->getPersonName().length();

                cout << "+------------------------------------------------------+" << endl;
                cout << "| " << positionsArray4[j] << "  | " << allEvents[i]->rosterOfPeople[j]->getPersonName();
                for (int s = 0; s < numberOfSpaces; s++)
                {
                    cout << " ";
                }
                cout << "|" << endl;
            }
            cout << "+------------------------------------------------------+" << endl;
        }

        //if there are 7 people in the team
        if (numberOfPeople == 7)
        {
            for (int j = 0; j < 7; j++)
            {
                int numberOfSpaces = 33 - allEvents[i]->rosterOfPeople[j]->getPersonName().length();

                cout << "+------------------------------------------------------+" << endl;
                cout << "| " << positionsArray7[j] << "  | " << allEvents[i]->rosterOfPeople[j]->getPersonName();
                for (int s = 0; s < numberOfSpaces; s++)
                {
                    cout << " ";
                }
                cout << "|" << endl;
            }
            cout << "+------------------------------------------------------+" << endl;
        }

        //if there are an unexpected number of people in the team
        if (numberOfPeople != 4 && numberOfPeople != 7)
        {

            //if less than 8 people, output the person and their position, centered in the space.
            if (numberOfPeople < 8)
            {
                for (int j = 0; j < numberOfPeople; j++)
                {
                    int numberOfSpaces = 33 - allEvents[i]->rosterOfPeople[j]->getPersonName().length();

                    cout << "+------------------------------------------------------+" << endl;
                    cout << "| " << positionsArray7[j] << "  | " << allEvents[i]->rosterOfPeople[j]->getPersonName();
                    for (int s = 0; s < numberOfSpaces; s++)
                    {
                        cout << " ";
                    }
                    cout << "|" << endl;
                }
                cout << "+------------------------------------------------------+" << endl;
            }
            //if more than 7, output the first 7 as normal, then print out "undefined role" for remaining assigned positions
            else
            {

                for (int j = 0; j < 7; j++)
                {
                    int numberOfSpaces = 33 - allEvents[i]->rosterOfPeople[j]->getPersonName().length();
                    cout << "+------------------------------------------------------+" << endl;

                    cout << "| " << positionsArray7[j] << "  | " << allEvents[i]->rosterOfPeople[j]->getPersonName();
                    for (int s = 0; s < numberOfSpaces; s++)
                    {
                        cout << " ";
                    }
                    cout << "|" << endl;
                }
                cout << "+------------------------------------------------------+" << endl;

                for (int l = 7; l < numberOfPeople; l++)
                {
                    int numberOfSpaces = 33 - allEvents[i]->rosterOfPeople[l]->getPersonName().length();

                    cout << "+------------------------------------------------------+" << endl;
                    cout << "| "
                         << "Undefined Role  "
                         << "  | " << allEvents[i]->rosterOfPeople[l]->getPersonName();
                    for (int s = 0; s < numberOfSpaces; s++)
                    {
                        cout << " ";
                    }
                    cout << "|" << endl;
                }
                cout << "+------------------------------------------------------+" << endl;
            }

            // printing the new line
            cout << "+------------------------------------------------------+" << endl;
        }

    }

    //output to csv
    outputCsv(allEvents);
    cout<< "*Csv File Created*"<<endl;
}