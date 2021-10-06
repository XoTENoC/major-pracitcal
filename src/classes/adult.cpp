
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

void adult::addContactInformation(std::string emailAddress, std::string phoneNumber){
    // Concatenating strings together to form a single contactInformation string.
    contactInformation = personName + ' ' + emailAddress + ' ' + phoneNumber;
}

void adult::removeContactInformation(){
    // Setting the string to empty;
    contactInformation = "N/A";
}

void adult::getContactInformation(){
    std::cout << contactInformation << std::endl;
}