// Author: Artur Cabral
/*
 _____ _             _            _     _____ _               
/  ___| |           | |          | |   /  __ \ |              
\ `--.| |_ _   _  __| | ___ _ __ | |_  | /  \/ | __ _ ___ ___ 
 `--. \ __| | | |/ _` |/ _ \ '_ \| __| | |   | |/ _` / __/ __|
/\__/ / |_| |_| | (_| |  __/ | | | |_  | \__/\ | (_| \__ \__ \
\____/ \__|\__,_|\__,_|\___|_| |_|\__|  \____/_|\__,_|___/___/
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
//Constructor: constructor for student has the extra code : Person(namey,SSNy) which CALLS the constructor for Person
// and passes in namey and SSNy, so the name and SSN are now set automatically
Student::Student(std::string namey, std::string SSNy, std::string majory, std::string SIDy, std::string yeary) : Person(namey, SSNy) {
	major = majory;
	SID = SIDy;
	year = yeary;

}
//Destructor:
Student::~Student() {};
//-------Student printInfo--------------------------------------
// prints major, SID, and year of the students
void Student::printInfo() {
	Person::printInfo(); // Call the print from the person class
	std::cout << "Major: \t" << major << std::endl;
	std::cout << "SID: \t" << SID << std::endl;
	std::cout << "Year: \t" << year << std::endl;
}
//------changeMajor-------------------------------------------
void Student::changeMajor(std::string newMajor) {
	major = newMajor;
}
//-------changeYear-------------------------------------------
void Student::changeYear(std::string newYear) {
	year = newYear;
}

//---getMajor--------------------------------------------------
std::string Student:: getMajor() {
	return(major);
}

//----getSID-------------------------------------------------
std::string Student:: getSID() {
	return(SID);
}

