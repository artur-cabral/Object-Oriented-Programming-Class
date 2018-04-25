// Author: Artur Cabral
/*
______                           _____ _
| ___ \                         /  __ \ |
| |_/ /__ _ __ ___  ___  _ __   | /  \/ | __ _ ___ ___
|  __/ _ \ '__/ __|/ _ \| '_ \  | |   | |/ _` / __/ __|
| | |  __/ |  \__ \ (_) | | | | | \__/\ | (_| \__ \__ \
\_|  \___|_|  |___/\___/|_| |_|  \____/_|\__,_|___/___/

*/

#include "Student.h"
#include "Person.h"
#include <iostream>
#include <string>

/*
______                _   _
|  ___|              | | (_)
| |_ _   _ _ __   ___| |_ _  ___  _ __  ___
|  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| | | |_| | | | | (__| |_| | (_) | | | \__ \
\_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/
//Constructor:
Person::Person(std::string initName, std::string initSSN) {
	setName(initName);
	SSN = initSSN;

}
//Constructor:(without SSN)
Person::Person(std::string initName) {
	setName(initName);

}
//Destructor:
Person::~Person() {};
//-----setName-----------------------------------------
void Person::setName(std::string newName) {
	name = newName;
}
//-------printInfo------------------------
void Person::printInfo() {
	std::cout << "Name: \t" << name << std::endl;
	std::cout << "SSN: \t" << SSN << std::endl;
}
//-----setSSN-----------------------------------------
void Person::setSSN(std::string setSSN) {
	SSN = setSSN;
}

//------getName-------------------------------------
std::string Person::getName() {
	return(name);
}

//-----getSSN---------------------------------------
std::string Person::getSSN() {
	return(SSN);
}