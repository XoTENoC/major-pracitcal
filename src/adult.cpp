#include <string>
#include <iostream>
#include "adult.h"

using namespace std;

void adult::setWorkingWithChildrenNumber(int aWorkingWithChildrenNumber){
    workingWithChildrenNumber = aWorkingWithChildrenNumber;
}

int adult::getWorkingWithChildrenNumber(){
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