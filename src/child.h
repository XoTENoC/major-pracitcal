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
    std::string contactInformation;
    int contactCount = 0;


    void addContactInformation(std::string contactName, std::string emailAddress, std::string phoneNumber);
    void removeContactInformation(int index);

    virtual void getContactInformation();
};

#endif