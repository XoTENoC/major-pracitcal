// child class inherits from parent class "person" to add behaviours and states which are unique to children only.
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
    }

    //TODO: Change contactInformation to a string array.

    void setContactInformation();
    void getContactInformation();

    private:
        std::string contactInformation[3] = {"0", "1", "2"};
        int contactCount = 0;

};

#endif