/* 

person.h

defines the abstract person class from which objects of type child and adult
are created.

*/

#ifndef PERSON_H
#define PERSON_H

#include<string>
using namespace std; 

class person{
    public:
        person();
        person(std::string aName, int aAge);

        // legend of array 
        // 0 - sound
        // 1 - lighting
        // 2 - computer graphics

        // legend of competencies
        // 0 = can't do
        // 1 = training
        // 2 = competent

        // returns the competency of the given person
        int getCompetency(int index);
        // takes in the interger from 0 to 2 for what postion and then another
        // interger from 0 to 2 to set the ability
        void setCompetency(int index, int aCompetency);

        // takes in a string of anylength and stores in the variable personName
        void setPersonName(std::string personName);
        // returns a string of the name of the person
        std::string getPersonName();

        // returns the age of a person as an interger
        int getAge();
        // takes in an interger and sets it to the variable age.
        void setAge(int age);

        // virual functions for setting the contact information and setting the
        // contant information.
        virtual void getContactInformation();
        virtual void setContactInformation();



        ~person();

        //MOVE THIS TO PROTECTED LATER

        bool isInEvent;

    private: 
        int competencies[3] = {};

    protected:
        std::string personName;
        int age;




};

#endif