#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"


// this function adds adults to the list of people, and also allows to add
// multiple people at once to allow for fast batch additions of people.
void addingPerson(vector<person*> &vectorPeople){

    cout << endl;

    int amountOfPeople = 0;
    string name;
    int age, competency;

    // asking how many people the user would like to add
    cout << "how many people would you like to add: ";
    cin >> amountOfPeople;

    for (int i = 0; i < amountOfPeople; i++){

        cout << endl;
        cout << "Person " << i+1 << endl;

        // asking for the name of the person
        cout << "what is the name of the person: ";
        cin >> name;

        //asking for the age of the person
        cout << "What is the age of the person: ";
        cin >> age;

        if (age >= 18)
        {
            cout << "adult Created" << endl;
            // adding the person to the array
            vectorPeople.push_back(new adult(name, age));

            // setting the competency
            cout << "ability at Sound: ";
            cin >> competency;

            vectorPeople.back()->setCompetency(0, competency);

            cout << "ability at Lighing: ";
            cin >> competency;

            vectorPeople.back()->setCompetency(1, competency);

            cout << "ability at Computer Graphics: ";
            cin >> competency;

            vectorPeople.back()->setCompetency(2, competency);
        }
        else
        {
            cout << "child Created" << endl;
            // adding the person to the array
            vectorPeople.push_back(new child(name, age));

            // setting the competency
            cout << "ability at Sound: ";
            cin >> competency;

            vectorPeople.back()->setCompetency(0, competency);

            cout << "ability at Lighing: ";
            cin >> competency;

            vectorPeople.back()->setCompetency(1, competency);

            cout << "ability at Computer Graphics: ";
            cin >> competency;

            vectorPeople.back()->setCompetency(2, competency);
        }
    }

}


// This function will print the list of people to the console
void listAllpeople(vector<person*> &vectorPeople){
    cout << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|                    List of People                    |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << endl;
    
    // listing all the people in the list
    int allThePeople = (int)vectorPeople.size();

    for(int i = 0; i < allThePeople; i++){
        cout << i + 1 << ": ";
        cout << vectorPeople[i]->getPersonName() << endl;
    }

    cout << endl;
}

void modifyPerson(vector<person*> &vectorPeople){

    // List all the people and there entries
    cout << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|                  list of Everything                  |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << endl;

    int allThePeople = (int)vectorPeople.size();

    for (int i = 0; i < allThePeople; i++){
        cout << i+1 << ": ";
        cout << vectorPeople[i]->getPersonName() << " ";
        cout << vectorPeople[i]->getAge() << " ";
        cout << vectorPeople[i]->getCompetency(0) << " ";
        cout << vectorPeople[i]->getCompetency(1) << " ";
        cout << vectorPeople[i]->getCompetency(2) << " ";
        cout << endl;
    }

    // add modify person details here

}

void addPerson(vector<person*> &vectorPeople, int * ammount){
    
    bool addingPeople = true;
    int choice = 0;

    while (addingPeople)
    {
        
        cout << endl;
        cout << "+------------------------------------------------------+" << endl;
        cout << "|                   Add a New Person                   |" << endl;
        cout << "+------------------------------------------------------+" << endl;
        cout << endl;

        // Printing the menu and asking for choice
        cout << "1 - add People" << endl;
        cout << "2 - Modify Entries" << endl;
        cout << "3 - exit" << endl;

        cin >> choice;

        // diciding where to go
        switch (choice)
        {
        case 1:
            addingPerson(vectorPeople);
            *ammount = (int)vectorPeople.size();
            break;

        case 2:
            modifyPerson(vectorPeople);
            break;

        case 3:
            addingPeople = false;
            break;

        default:
            break;
        }
    }
    


}