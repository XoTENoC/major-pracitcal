// child class inherits from parent class "person" to add behaviours and states which are unique to children only.

#include <string>
#include <iostream>
#include "child.h"

using namespace std;

void child::addContactInformation(std::string contactName, std::string emailAddress, std::string phoneNumber){
    //TODO make this function dynamically allocate an array (see different branch).
    // Concatenating strings together to form a single contactInformation string.
    contactInformation[contactCount] = contactInformation[contactCount] +  " " + contactName + ' ' + emailAddress + ' ' + phoneNumber;
    contactCount++;
}

void child::removeContactInformation(){
    // TODO: remove contact information at an index and re construct the array.
    for(int i=0; i<3; i++){
        contactInformation[i] = std::to_string(i);
    }
}


void child::getContactInformation(){
    std::cout << getPersonName() << " Contact Information: " << std::endl;
    for(int i=0; i<3; i++){
        std::cout << contactInformation[i] << std::endl;
    }
}