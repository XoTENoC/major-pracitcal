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
    // A void type is used so that the adult class may output a single string while the child class can output multiple lines of contacts.
}

void person::setContactInformation(){
    
}

int person::getCompetency(int index){
    return competencies[index];
}

void person::setCompetency(int index, int aCompetency){
    competencies[index] = aCompetency;
}