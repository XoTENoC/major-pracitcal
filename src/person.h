#ifndef PERSON_H
#define PERSON_H

#include<string>
using namespace std; 

class person{
    public:
    person();
    person(std::string aName, int aAge);

    // ledgend of array 
    // 0 - sound
    // 1 - lighting
    // 2 - computer graphics

    int competencies[3] = {};

    int getCompetency(int index);
    int setCompetency(int index, int aCompetency);

    std::string personName;
    std::string getPersonName();
    void setPersonName(std::string personName);

    int age;
    int getAge();
    void setAge(int age);

    virtual void getContactInformation();

    ~person();

};

#endif