// Author: Artur Cabral
/*
______           __                           _____ _
| ___ \         / _|                         /  __ \ |
| |_/ / __ ___ | |_ ___  ___ ___  ___  _ __  | /  \/ | __ _ ___ ___
|  __/ '__/ _ \|  _/ _ \/ __/ __|/ _ \| '__| | |   | |/ _` / __/ __|
| |  | | | (_) | ||  __/\__ \__ \ (_) | |    | \__/\ | (_| \__ \__ \
\_|  |_|  \___/|_| \___||___/___/\___/|_|     \____/_|\__,_|___/___/
*/


#include "Student.h"
#include "Person.h"
#include "Professor.h"
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
//constructor--------------------------------------------------------------------------------------
Professor::Professor(std::string namey, std::string SSNy, std::string titley, std::string depty) : Person(namey, SSNy) {
	title = titley; dept = depty;

}

//destructor---------------------------------------------------
Professor::~Professor() {};

//-------Professor printInfo-----------------------------------
// this function prints out the info for the selected professor
void Professor::printInfo() {
	Person::printInfo();
	std::cout << "Title: \t" << title << std::endl;
	std::cout << "Dept: \t" << dept << std::endl;
}
//----- changeTitle ----------------------------------------------
// this function changes the title of the selected professor
void Professor::changeTitle(const std::string &newTitle) {
	title = newTitle;
}

//---getDept--------------------------------------------------
std::string Professor::getDept() {
	return(dept);
}
//---getTitle--------------------------------------------------
std::string Professor::getTitle() {
	return(title);
}