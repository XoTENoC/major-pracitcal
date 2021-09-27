#include "person.h"
#include "child.h"
#include <iostream>

int main(){
	child tim("Tim", 14);
	std::cout << tim.getPersonName() << " " <<  tim.getAge() << std::endl;

	tim.addContactInformation("self", "email", "01234");

	tim.addContactInformation("father", "email", "1234");
	

	tim.getContactInformation();

	tim.addContactInformation("mother", "email", "2345");

	tim.getContactInformation();
}
