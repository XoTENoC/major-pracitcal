#include<string>
#include "person.h"

using namespace std; 


person::person(){



}

person::~person(){


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

int person::getContactNumber(){

    return contactNumber;
}

void person::setContactNumber(){

    
}