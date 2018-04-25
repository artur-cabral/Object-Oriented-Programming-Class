/* Polymorphism LAB
 _       ___  ______   _____
| |     / _ \ | ___ \ |  ___|
| |    / /_\ \| |_/ / |___ \
| |    |  _  || ___ \     \ \
| |____| | | || |_/ / /\__/ /
\_____/\_| |_/\____/  \____/

*/
//-----------------------------------------------------------------------
// Author: Artur Cabral
// Summary: the goal of this lab is to get some practice in polymorphism in classes.
// the program should get the array of allPeople including the professor, and print all of their
//names and SSN. Then, it should change the SSN and SID of two students and print the roster of the
//class in the formatted form using a separate function called printRoster
// Important Classes: Person(the main class, which takes in name and SSN), Student( inherited in Person
//class, and also adds major, SID, and year to a student), and Professor ( also inherited in Person,
//adds title, and dept to the professor)
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Professor.h"



void printRoster(Person theProf, Student *theStudents[]) {
	//print professors name:
	std::cout << "CS 210 Instructor: " << theProf.getName() << std::endl;

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
	Professor myProfessor("Dr. Dostert", "123456789", "Assoc. Professor", "CS/MAT");
	//Create Students
	Student *myStudents[9];
	myStudents[0] = new Student("Artur Cabral", "112233445", "CS", "0292651", "SR");
	myStudents[1] = new Student("Edward Leitgeb", "112233556", "CS", "1234567", "SO");
	myStudents[2] = new Student("Scott Burnley", "333233445", "MAT", "4569871", "SR");
	myStudents[3] = new Student("Dakota Purvis", "144778855", "CS", "2255889", "JR");
	myStudents[4] = new Student("Emily Shepherd", "22336558", "CS", "8855223", "JR");
	myStudents[5] = new Student("Caleb Jordan", "154785698", "CS", "2656651", "JR");
	myStudents[6] = new Student("Katie Chambers", "999933445", "MAT", "7788554", "SO");
	myStudents[7] = new Student("Van Seiler", "998877445", "CS", "4567999", "JR");
	myStudents[8] = new Student("Temaris Dixon", "225544117", "CS", "6633225", "SO");
	//Put all students and professor into an arrray of Person
	Person *allPeople[10];//get all the students first (can I do that?)
	for (int i = 0; i < 9; i++) {
		allPeople[i] = myStudents[i];
	}
	//now get the professor
	allPeople[9] = &myProfessor;

	//Loop through all of the members of the Person class
	//Print out Name and SSN
	for (int i = 0; i < 10; i++) {
		allPeople[i]->Person::printInfo();
		std::cout << "\n";
	}
	//Change SSN and SID of TWO students
	myStudents[1]->setSSN("111111111");
	myStudents[2]->setSSN("222222222");
	myStudents[1]->changeSID("7777777");
	myStudents[2]->changeSID("8888888");
		
	//Print out this information using a separate function
	printRoster(myProfessor, myStudents);

	

	system("pause");
	return(0);
}
