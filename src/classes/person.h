//defines the abstract person class from which objects of type child and adult are created. 

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
    

    int getCompetency(int index);
    void setCompetency(int index, int aCompetency);

    
    void setPersonName(std::string personName);

    int getAge();
    void setAge(int age);

    virtual void getContactInformation();
    virtual void setContactInformation();

    std::string getPersonName();


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