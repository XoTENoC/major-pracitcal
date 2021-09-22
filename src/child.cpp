#include <string>
#include <iostream>
#include "child.h"

using namespace std;

void child::addContactInformation(std::string contactName, std::string emailAddress, std::string phoneNumber){
    //TODO make this function dynamically allocate an array.
    // Concatenating strings together to form a single contactInformation string.
    contactInformation = std::to_string(contactCount + 1) + contactName + ' ' + emailAddress + ' ' + phoneNumber;
}

void child::removeContactInformation(int index){
    //TODO remove location at index (see child.h)
    contactInformation = "N/A";
}

void child::getContactInformation(){
    //TODO make this loop through array (see child.h)
    std::cout << contactInformation << std::endl;
}