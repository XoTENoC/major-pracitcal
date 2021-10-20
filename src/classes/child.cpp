// child class inherits from parent class "person" to add behaviours and states which are unique to children only.

#include <string>
#include <iostream>
#include "child.h"

using namespace std;

void child::setContactInformation(){
    string contactName, emailAddress, phoneNumber, relation;

    cout << "Child email address: ";
    cin >> emailAddress;

    cout << "Child phone number: ";
    cin >> phoneNumber;

    contactInformation[0] = "1 " + personName + ' ' + emailAddress + ' ' + phoneNumber;

    for(int i=1; i<3; i++){
        cout << "Parent/Guardian " << i << endl;

        cout << "Relation: ";
        cin >> relation;

        cout << "Name: ";
        cin >> contactName;

        cout << "Email address: ";
        cin >> emailAddress;

        cout << "Phone number: ";
        cin >> phoneNumber;

        contactInformation[i] = to_string(i+1) + "(" + relation + ") " + contactName + ' ' + emailAddress + ' ' + phoneNumber;
    }

    // Concatenating strings together to form a single contactInformation string.
    contactInformation[contactCount] = contactInformation[contactCount] +  " " + contactName + ' ' + emailAddress + ' ' + phoneNumber;
    contactCount++;
}

string* child::getContactInformation(){
    return contactInformation;
}