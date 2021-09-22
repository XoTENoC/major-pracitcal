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

void person::getContactInformation(){
    // A void type is used so that the adult class may output a single string while the child class can output multiple lines of contacts.
}

void person::setComputerGraphicsCapability(int aCGAbility){

    computerGraphicsCapability = aCGAbility;
}

int person::getComputerGraphicsCapability(){

    return computerGraphicsCapability;
}

void person::setLightingCapability(int aLightingAbility){

    lightingCapability = aLightingAbility;
}

int person::getLightingCapability(){

    return lightingCapability;
}

void person::setSoundCapability(int aSoundAbility){

    soundCapability = aSoundAbility;
}

int person::getSoundCapability(){

    return soundCapability;
}

