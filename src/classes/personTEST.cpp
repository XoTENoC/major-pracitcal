#include "person.h"
#include "adult.h"
#include <iostream>

int main(){
	adult austen("Austen", 19);
	std::cout << austen.getPersonName() << " " <<  austen.getAge() << std::endl;

	austen.setWorkingWithChildrenNumber(12345);
	std::cout << austen.getWorkingWithChildrenNumber() << std::endl;

	austen.addContactInformation("aalindsay@me.com", "0451021891");
	austen.getContactInformation();
	austen.removeContactInformation();
	austen.getContactInformation();
}

