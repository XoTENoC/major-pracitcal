#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/person.h"
#include "../classes/adult.h"
#include "../classes/child.h"
#include "../classes/events.h"
#include <fstream>
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>   // std::stringstream

using namespace std;
//Note: most of the code for csv read comes from https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/, only edited so that a person is added, and got rid of some redundant code.
//should be further customised for our purposes!
std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename)
{
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<int>>> result;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if (!myFile.is_open())
        throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;
    int val;

    // Read the column names
    if (myFile.good())
    {
        // Extract the first line in the file
        std::getline(myFile, line);
        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while (std::getline(ss, colname, ','))
        {

            // Initialize and add <colname, int vector> pairs to result
            result.push_back({colname, std::vector<int>{}});
        }
    }

    // Read data, line by line
    while (std::getline(myFile, line))
    {

        // Create a stringstream of the current line
        std::stringstream ss(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each integer
        while (ss >> val)
        {
            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            cout << "working" << val << endl;
            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',')
                ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    return result;
}

// this function adds adults to the list of people, and also allows to add
// multiple people at once to allow for fast batch additions of people.
void addingPerson(vector<person *> &vectorPeople)
{

    cout << endl;

    int amountOfPeople = 0;
    string name;
    int age, competency;

    // asking how many people the user would like to add
    cout << "how many people would you like to add: ";
    cin >> amountOfPeople;

    for (int i = 0; i < amountOfPeople; i++)
    {

        cout << endl;
        cout << "Person " << i + 1 << endl;

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
void listAllpeople(vector<person *> &vectorPeople)
{
    cout << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|                    List of People                    |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << endl;

    // listing all the people in the list
    int allThePeople = (int)vectorPeople.size();

    for (int i = 0; i < allThePeople; i++)
    {
        cout << i + 1 << ": ";
        cout << vectorPeople[i]->getPersonName() << endl;
    }

    cout << endl;
}

void modifyPerson(vector<person *> &vectorPeople)
{

    // List all the people and there entries
    cout << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|                  list of Everything                  |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << endl;

    int allThePeople = (int)vectorPeople.size();

    for (int i = 0; i < allThePeople; i++)
    {
        cout << i + 1 << ": ";
        cout << vectorPeople[i]->getPersonName() << " ";
        cout << vectorPeople[i]->getAge() << " ";
        cout << vectorPeople[i]->getCompetency(0) << " ";
        cout << vectorPeople[i]->getCompetency(1) << " ";
        cout << vectorPeople[i]->getCompetency(2) << " ";
        cout << endl;
    }

    // add modify person details here
}

void addFromCsv(vector<person *> &vectorPeople)
{

    std::vector<std::pair<std::string, std::vector<int>>> people = read_csv("People.csv");
    int numArguments = (int)people.size();

    string thisName = people[0].first;

    int thisAge = stoi(people[1].first);
    int thisSound = stoi(people[2].first);
    int thisLight = stoi(people[3].first);
    int thisCG = stoi(people[4].first);
    vectorPeople.push_back(new adult(thisName, thisAge));
    vectorPeople.back()->setCompetency(0, thisSound);
    vectorPeople.back()->setCompetency(1, thisLight);
    vectorPeople.back()->setCompetency(0, thisCG);

}

void addPerson(vector<person *> &vectorPeople, int *ammount)
{

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
        cout << "4 - Add from csv" << endl;

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

        case 4:
            addFromCsv(vectorPeople);
            break;

        default:
            break;
        }
    }
}