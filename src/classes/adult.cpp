
// Adult class inherits from parent class "person" to add behaviours and states which are unique to adults only.

#include <string>
#include <iostream>
#include "adult.h"

using namespace std;

void adult::setWorkingWithChildrenNumber(std::string aWorkingWithChildrenNumber){
    workingWithChildrenNumber = aWorkingWithChildrenNumber;
}

string adult::getWorkingWithChildrenNumber(){
    return workingWithChildrenNumber;
}

void adult::setContactInformation(){
    string emailAddress, phoneNumber;

    cout << "Email address: ";
    cin >> emailAddress;

    cout << "Phone number: ";
    cin >> phoneNumber;

    // Concatenating strings together to form a single contactInformation string.
    contactInformation = personName + ' ' + emailAddress + ' ' + phoneNumber;

    contactPointer = &contactInformation;
    hasContactInformation = true;
}

string* adult::getContactInformation(){
    return contactPointer;
}