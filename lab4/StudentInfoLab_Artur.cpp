//------LAB 4_ClassArrays----------------------------------------------------------------------------------------
// Author: Artur Cabral
// Summary: The goal of this lab is to practice the use of classes, header files, and to create a class roster
// and print some information
// Important Classes: Person(gets name and SSN), Student(inherited in Person, and also gets major, SID, year)
//---------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"

//-----printRoster---------------------------------------------------------------
//this function prints the class roster in a nice style, geting the instructor's 
//name, and also prints the students name, major and SID.
//-------------------------------------------------------------------------------
void printRoster(Person theProf, Student *theStudents[]) {
	//print professors name:
	std::cout << "CS 210 Instructor: "<< theProf.getName()<<std::endl;
	
	std::cout << "\nClass Roster\n\n";
	std::cout << "\nNAME\t\t\t\tMAJOR\tSID\n\n";
	for (int i = 0; i < 9; i++) {
		std::cout << theStudents[i]->getName() << "\t\t\t" << theStudents[i]->getMajor() << "\t" << theStudents[i]->getSID() << std::endl;
	}
	std::cout << "\n" << std::endl;
}
	/*
___  ___      _       
|  \/  |     (_)      
| .  . | __ _ _ _ __  
| |\/| |/ _` | | '_ \ 
| |  | | (_| | | | | |
\_|  |_/\__,_|_|_| |_|
                      
	*/

	int main() {
		//Create Professor
		Person myProfessor("Dr. Dostert", "123456789");
		//Create Students
		Student *myStudents[9];
		myStudents[0] = new Student("Artur Cabral", "112233445","CS", "292651", "SR" );
		myStudents[1] = new Student("Edward Leitgeb", "112233556", "CS", "1234567", "SO");
		myStudents[2] = new Student("Scott Burnley", "333233445", "MAT", "4569871", "SR");
		myStudents[3] = new Student("Dakota Purvis", "144778855", "CS", "2255889", "JR");
		myStudents[4] = new Student("Emily Shepherd", "22336558", "CS", "8855223", "JR");
		myStudents[5] = new Student("Caleb Jordan", "154785698", "CS", "2656651", "JR");
		myStudents[6] = new Student("Katie Chambers", "999933445", "MAT", "7788554", "SO");
		myStudents[7] = new Student("Van Seiler", "998877445", "CS", "4567999", "JR");
		myStudents[8] = new Student("Temaris Dixon", "225544117", "CS", "6633225", "SO");
		//Print Roster
		printRoster(myProfessor,myStudents);
		//Change TWO Majors
		myStudents[3]->changeMajor("PHY");
		myStudents[5]->changeMajor("BUS");
		//Reprint Roster
		printRoster(myProfessor, myStudents);
		system("pause");
		return(0);
	}