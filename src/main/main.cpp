#include <iostream>
#include <string>
#include <vector>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"
#include "../functions/addingPerson.h"
#include "../functions/addingRoster.h"
#include "../functions/viewRoster.h"
#include "../functions/inputValidation.h"
using namespace std;
void printBlurb(){

    cout << "+------------------------------------------------------+" << endl;
    cout << "|                                                      |"<<endl;
    cout << "|  ██████╗  ██████╗ ███████╗████████╗███████╗██████╗   |"<<endl;
    cout << "|  ██╔══██╗██╔═══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗  |"<<endl;
    cout << "|  ██████╔╝██║   ██║███████╗   ██║   █████╗  ██████╔╝  |"<<endl;
    cout << "|  ██╔══██╗██║   ██║╚════██║   ██║   ██╔══╝  ██╔══██╗  |"<<endl;
    cout << "|  ██║  ██║╚██████╔╝███████║   ██║   ███████╗██║  ██║  |"<<endl;
    cout << "|  ╚═╝  ╚═╝ ╚═════╝ ╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝  |"<<endl;
    cout << "|   Nathaniel Chang, Austen Lindsay, Sophie Davidson   |"<<endl;
    cout << "|     2021 Semester 2 - Object Oriented Programming    |"<<endl;
    cout << "|                                                      |"<<endl;
    cout << "|      A event - based automated rostering system      |"<<endl;
    cout << "|                                                      |"<<endl;
    cout << "+------------------------------------------------------+" << endl;
}
// Adding Test Data
void addingTestPeople(vector<person*> &vectorPeople){
    
    vectorPeople.push_back(new adult("Obiwan", 100));
    vectorPeople.back()->setCompetency(0, 2);
    vectorPeople.back()->setCompetency(1, 2);
    vectorPeople.back()->setCompetency(2, 2);

    vectorPeople.push_back(new adult("Anikin", 15));
    vectorPeople.back()->setCompetency(0, 1);
    vectorPeople.back()->setCompetency(1, 2);
    vectorPeople.back()->setCompetency(2, 2);

    vectorPeople.push_back(new adult("Luke", 20));
    vectorPeople.back()->setCompetency(0, 0);
    vectorPeople.back()->setCompetency(1, 0);
    vectorPeople.back()->setCompetency(2, 2);

    vectorPeople.push_back(new adult("Vader", 60));
    vectorPeople.back()->setCompetency(0, 0);
    vectorPeople.back()->setCompetency(1, 2);
    vectorPeople.back()->setCompetency(2, 0);

    vectorPeople.push_back(new adult("jaja", 40));
    vectorPeople.back()->setCompetency(0, 1);
    vectorPeople.back()->setCompetency(1, 1);
    vectorPeople.back()->setCompetency(2, 0);

    vectorPeople.push_back(new adult("padme", 30));
    vectorPeople.back()->setCompetency(0, 2);
    vectorPeople.back()->setCompetency(1, 2);
    vectorPeople.back()->setCompetency(2, 2);

    vectorPeople.push_back(new adult("Liea", 20));
    vectorPeople.back()->setCompetency(0, 1);
    vectorPeople.back()->setCompetency(1, 1);
    vectorPeople.back()->setCompetency(2, 1);

    vectorPeople.push_back(new adult("yoda", 130));
    vectorPeople.back()->setCompetency(0, 2);
    vectorPeople.back()->setCompetency(1, 2);
    vectorPeople.back()->setCompetency(2, 0);

    vectorPeople.push_back(new adult("Han.Solo", 130));
    vectorPeople.back()->setCompetency(0, 0);
    vectorPeople.back()->setCompetency(1, 0);
    vectorPeople.back()->setCompetency(2, 1);
}

int main(){

    // clearing the screen
    system("clear");

    // printing the title of the program
    printBlurb();
    // Starting the program
    bool inProgram = true;
    bool mainMenu = true;

    // list of people
    vector<person*> people;
    vector<events*> allEvents;

    // setting all the test data
    addingTestPeople(people);


    // init variables
    int amount = 0;
    int choice = 0;
    int choices[7] = {1, 2, 3, 4, 5, 6, 7};

    while(inProgram){
        
        // MAIN MENU
        mainMenu = true;
        while(mainMenu){

            cout << endl;
            cout << "+------------------------------------------------------+" << endl;
            cout << "|                      Main Menu                       |" << endl;
            cout << "+------------------------------------------------------+" << endl;
            cout << endl;

            cout << "1 - Add a new person" << endl;
            cout << "2 - Remove a person" << endl;
            cout << "3 - View all the people" << endl;
            cout << "4 - Add an Event" << endl;
            cout << "5 - Remove an Event" << endl;
            cout << "6 - View roster" << endl;
            cout << "7 - Exit" << endl;

            choice = inputNumStatic(choices, 7);

            switch(choice){
                // adding a person the array of people
                case 1:
                    addPerson(people, &amount);
                    break;
                case 2:
                    removePerson(people);
                    break;
                case 3:
                    listAllpeople(people);
                    break;
                case 4:
                    addEvent(allEvents, people);
                    break;
                case 5:
                    removeEvent(allEvents);
                    break;
                case 6:
                    displayRoster(allEvents);
                    break;
                case 7:
                    mainMenu = false;
                    inProgram = false;
                    break;
            }
        }

    }

}