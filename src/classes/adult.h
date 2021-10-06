// Adult class inherits from parent class "person" to add behaviours and states which are unique to adults only.

#include "person.h"
#ifndef ADULT_H
#define ADULT_H

#include <string>
using namespace std;

class adult: public person{

    public:

    // Constructor derived of abstract person class.
    adult(std::string aName, int aAge): person(){
        personName = aName;
        age = aAge;
    }

    string workingWithChildrenNumber;
    void setWorkingWithChildrenNumber(string aWorkingWithChildrenNumber);
    string getWorkingWithChildrenNumber();

    std::string contactInformation;
    void addContactInformation(std::string emailAddress, std::string phoneNumber);
    void removeContactInformation();

    virtual void getContactInformation();
};

#endif