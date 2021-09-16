#ifndef PERSON_H
#define PERSON_H


#include<string>
using namespace std; 

class person{
    public:
    person();

    std::string personName;
    std::string getPersonName();
    void setPersonName(std::string personName);

    int soundCapability;
    int getSoundCapability();
    void setSoundCapability(int capability);

    int lightingCapability;
    int getLightingCapability();
    void setLightingCapability(int capability);

    int computerGraphicsCapability;
    int getComputerGraphicsCapability();
    void setComputerGraphicsCapability(int capability);

    int age;
    int getAge();
    void setAge(int age);

    int contactNumber;
    void setContactNumber();
    int getContactNumber(int contactNumber);

    ~person();

};


#endif