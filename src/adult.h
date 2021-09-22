#include "person.h"
#ifndef ADULT_H
#define ADULT_H

#include <string>
using namespace std;

class adult: public person{

    public:

    // Constructor derived of person class.
    adult(std::string aName, int aAge): person(){
        personName = aName;
        age = aAge;
    }

    int workingWithChildrenNumber;
    void setWorkingWithChildrenNumber(int aWorkingWithChildrenNumber);
    int getWorkingWithChildrenNumber();

    std::string contactInformation;
    void addContactInformation(std::string emailAddress, std::string phoneNumber);
    void removeContactInformation();

    virtual void getContactInformation();
};

#endif