#include <string>
#include "person.h"
#include "adult.h"
#include "child.h"

using namespace std;

void addingAdult(){

    // SEND HELP!

                // creating a new array person
                tempArrayOfPerople = new person[*ammount];

                for (int i = 0; i < *ammount; i++){
                    arr[i] = tempArrayOfPerople[i];
                }

                delete[] arr;
                // id of people incease
                *ammount++;
                arr = new person[*ammount]; 

                for (int i = 0; i < *ammount-1; i++){
                    tempArrayOfPerople[i] = arr[i];
                }

                delete[] tempArrayOfPerople;
                
                cout << "name for the person: ";
                cin >> name;

                cout << "Age of the person: ";
                cin >> age;

                arr[*ammount] = adult(name, age);

                cout << "ability of sound: ";
                cin >> competency;

                arr[*ammount].setCompetency(0, competency);

                cout << "ability of lighting: ";
                cin >> competency;

                arr[*ammount].setCompetency(1, competency);

                cout << "ability of computer graphics: ";
                cin >> competency;

}