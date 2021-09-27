#include <iostream>
#include "person.h"
#include "child.h"

int main(){
	child tim("Tim", 14);

	if(tim.getPersonName()!="Tim" || tim.getAge()!=14){
		return 0;
	}

	tim.addContactInformation("self", "email", "01234");

	tim.addContactInformation("father", "email", "1234");
	

	tim.addContactInformation("mother", "email", "2345");

	if(tim.contactInformation[0]!="0 self email 01234"){
		return 0;
	}

	if(tim.contactInformation[1]!="1 father email 1234"){
		return 0;
	}

	if(tim.contactInformation[2]!="2 mother email 2345"){
		return 0;
	}

	cout << "true" << endl;

}
