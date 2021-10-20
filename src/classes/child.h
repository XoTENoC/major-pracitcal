/* 

child.h

child class inherits from parent class "person" to add behaviours and states
which are unique to children only.

*/

#include "person.h"
#ifndef CHILD_H
#define CHILD_H

#include <string>
using namespace std;

class child: public person{

    public:

    // Constructor derived of person class.
    child(std::string aName, int aAge): person(){
        personName = aName;
        age = aAge;
        contactInformation = new string[3];
    }

    //TODO: Change contactInformation to a string array.

    void setContactInformation();
    string* getContactInformation();

    // Pointer to the array of contact informations.
    string* contactInformation = new string[3];

    private:

};

#endif