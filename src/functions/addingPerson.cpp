#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"
#include "inputValidation.h"
#include <fstream>
#include<math.h>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

using namespace std;

vector<string> splitString(string str) 
{ 
    vector<string> contentsOfLine;
   string w = ""; 
   for (auto rem : str) 
   { 
       if (rem==',') 
       { 
            contentsOfLine.push_back(w);
           w=""; 
       } 
       else
       { 
           w=w+rem; 
       } 

   }  
   cout<<w<<endl; 
   return contentsOfLine;
} 
void addFromCsv2(string fileName, vector<person*> &vectorPeople){
    short loop=0; 
    string line; 
    //opening file
    ifstream myfile (fileName); 
    if (myfile.is_open()) 
    {
        //until the end of the file
        while (! myfile.eof() ) 
        {
            //get the current line
            getline (myfile,line); 
            //split the string by commas
            vector<string> split = splitString(line);
            //define each column, and set for each person
            string thisName = split[0];
            int thisAge = stoi(split[1]);
            int sound = stoi(split[2]);
            int lighting = stoi(split[3]);
            int cg = stoi(split[4]);

            //if adult, add an adult with the correct info.
            if(thisAge>17){
            vectorPeople.push_back(new adult(thisName, thisAge));
            vectorPeople.back()->setCompetency(0, sound);
            vectorPeople.back()->setCompetency(1,lighting);
            vectorPeople.back()->setCompetency(2,cg);
            }
            else{
            vectorPeople.push_back(new child(thisName, thisAge));
            vectorPeople.back()->setCompetency(0, sound);
            vectorPeople.back()->setCompetency(1,lighting);
            vectorPeople.back()->setCompetency(2,cg);
            }
            loop++;
        }
        cout<< loop <<" people added from csv"<<endl;
        myfile.close(); 
    }
    else cout << "file not found"; 
}


// this function adds adults to the list of people, and also allows to add
// multiple people at once to allow for fast batch additions of people.
void addingPerson(vector<person*> &vectorPeople){
    cout << endl;

    int amountOfPeople = 0;
    string name;
    int age, competency;
    int competencies[3] = {0,1,2};

    // asking how many people the user would like to add
    cout << "how many people would you like to add: ";
    cin >> amountOfPeople;

    for (int i = 0; i < amountOfPeople; i++){

        cout << endl;
        cout << "Person " << i+1 << endl;

        // asking for the name of the person
        cout << "what is the name of the person: ";
        name = intputStringAmmount(25);

        //asking for the age of the person
        cout << "What is the age of the person: ";
        cin >> age;

        if (age >= 18)
        {
            cout << "adult Created" << endl;
            // adding the person to the array
            vectorPeople.push_back(new adult(name, age));
            cout<<endl; 
            cout<<"For the following criteria, please enter 0 for no ability, 1 for trainee, 2 for operator."<<endl;
            // setting the competency
            cout << "ability at Sound: ";
            competency = inputNumStatic(competencies, 3);

            vectorPeople.back()->setCompetency(0, competency);

            cout << "ability at Lighing: ";
            competency = inputNumStatic(competencies, 3);

            vectorPeople.back()->setCompetency(1, competency);

            cout << "ability at Computer Graphics: ";
            competency = inputNumStatic(competencies, 3);

            vectorPeople.back()->setCompetency(2, competency);
        }
        else
        {
            cout << "child Created" << endl;
            // adding the person to the array
            vectorPeople.push_back(new child(name, age));
            cout<<endl; 
            cout<<"For the following criteria, please enter 0 for no ability, 1 for trainee, 2 for operator."<<endl;
            // setting the competency
            cout << "ability at Sound: ";
            competency = inputNumStatic(competencies, 3);

            vectorPeople.back()->setCompetency(0, competency);

            cout << "ability at Lighing: ";
            competency = inputNumStatic(competencies, 3);

            vectorPeople.back()->setCompetency(1, competency);

            cout << "ability at Computer Graphics: ";
            competency = inputNumStatic(competencies, 3);

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
    
    //finding the number of people
    int allThePeople = (int)vectorPeople.size();

    cout << "+------------------------------------------------------+" << endl;
        cout << "| Name                           |Age|Sound|Lighting|CG|" << endl;
        cout << "+------------------------------------------------------+" << endl;

        //looping through all people
    for(int i = 0; i < allThePeople; i++){
        //if there are 2 digits, reduce the number of spaces by 1
        int numberOfSpaces=30;
            if(i>8){numberOfSpaces= numberOfSpaces-1;}

        //determining the length of the person's name
        int nameLength = vectorPeople[i]->getPersonName().length();

        //printing out the index, and the person's name
        cout << "|"<<i+1<<":"<<vectorPeople[i]->getPersonName();

        //printing out filler spaces as precalculated, subtracting the person's name
        for(int f= 0;f<numberOfSpaces-nameLength;f++){
            cout<<" ";
        }

        //printing out the person's age, subtracting the number of digits of their age.
        cout<<"|"<<vectorPeople[i]->getAge();
        for(int f=0;f<2-log10(vectorPeople[i]->getAge());f++){
            cout<<" ";
        }

        //printing out the competencies
        cout<<"|"<<vectorPeople[i]->getCompetency(0)<<"    |"<<vectorPeople[i]->getCompetency(1)<<"       |"<<vectorPeople[i]->getCompetency(2)<<" |"<<endl;
                cout << "+------------------------------------------------------+" << endl;

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
    int choices[4] = {1, 2, 3,4};

    while (addingPeople)
    {
        
        cout << endl;
        cout << "+------------------------------------------------------+" << endl;
        cout << "|                   Add a New Person                   |" << endl;
        cout << "+------------------------------------------------------+" << endl;
        cout << endl;

        // Printing the menu and asking for choice
        cout << "1 - Add People" << endl;
        cout << "2 - Modify Entries" << endl;
        cout << "3 - Add People From CSV" << endl;
        cout<< "4 - exit"<<endl;
        choice = inputNumStatic(choices, 4);

        string lines[100]; 

        // deciding where to go
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
            addFromCsv2("People.csv", /*lines,*/ vectorPeople);

            break;

        case 4:
            addingPeople = false;

            break; 

        default:
            break;
        }
    }
    


}







