#include <iostream>
#include<string>
#include "person.h"

using namespace std; 

person::person(){

}

person::~person(){
    // Comment this in for
    // std::cout << "Destroying " << personName << std::endl;
}

void person::setAge(int aAge){
    age = aAge;
}

int person::getAge(){
return age;
}

void person::setPersonName(std::string aName){
    personName = aName;
}

std::string person::getPersonName(){
    return personName;
} 

string* person::getContactInformation(){

}

void person::setContactInformation(){
    
}

int person::getCompetency(int index){
    return competencies[index];
}

void person::setCompetency(int index, int aCompetency){
    competencies[index] = aCompetency;
}