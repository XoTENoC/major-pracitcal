/* 

adult.h

Adult class inherits from parent class "person" to add behaviours and
states which are unique to adults only.

*/

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

        // takes in a string of any length and assigns it to the variable
        // workingWithChildrenNumber
        void setWorkingWithChildrenNumber(string aWorkingWithChildrenNumber);
        // returns the variable workingWithChildrenNumber
        string getWorkingWithChildrenNumber();

        // takes in a string of any length for the email and string of anylength
        // for the phone number
        void setContactInformation();

        void addContactInformation(std::string emailAddress, std::string phoneNumber);
        void removeContactInformation();

        // returning the contant information to the user.
        virtual void getContactInformation();

    private:
        string workingWithChildrenNumber;
        std::string contactInformation;


};

#endif