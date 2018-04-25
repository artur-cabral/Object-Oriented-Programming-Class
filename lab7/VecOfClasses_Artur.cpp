#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Professor.h"

//Function PrintRoster: to print the roster with the Professors and students names all together
void printRoster(std::vector<Professor> theProfessors, std::vector<Student> theStudents) {
	//print professors name:
	std::cout << "CS 210 Instructors: " << std::endl;
	for (auto profItr = theProfessors.begin(); profItr<theProfessors.end(); profItr++) {
		std::cout << profItr->getName() << "\t\t\t" << profItr->getTitle() << "\t" << profItr->getDept() << "\t" << std::endl;
	}

	std::cout << "\nClass Roster\n\n";
	std::cout << "\nNAME\t\t\t\tMAJOR\tSID\n\n";
	for (auto studItr=theStudents.begin(); studItr<theStudents.end(); studItr++) {
		std::cout << studItr->getName() << "\t\t\t" << studItr->getMajor() << "\t" << studItr->getSID() << std::endl;
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
	std::cout << "==== CS 210 STUDENTS INFO ====" << std::endl;
	//Create a vector of Student, where each entry is one of your classmates
	std::vector <Student> students;
	students.push_back(Student("Artur Cabral", "112233445", "CS", "0292651", "SR"));
	students.push_back(Student("Edward Leitgeb", "112233556", "CS", "1234567", "SO"));
	students.push_back(Student("Scott Burnley", "333233445", "MAT", "4569871", "SR"));
	students.push_back(Student("Dakota Purvis", "144778855", "CS", "2255889", "JR"));
	students.push_back(Student("Emily Shepherd", "22336558", "CS", "8855223", "JR"));
	students.push_back(Student("Caleb Jordan", "154785698", "CS", "2656651", "JR"));
	students.push_back(Student("Katie Chambers", "999933445", "MAT", "7788554", "SO"));
	students.push_back(Student("Van Seiler", "998877445", "CS", "4567999", "JR"));
	students.push_back(Student("Temaris Dixon", "225544117", "CS", "6633225", "SO"));
	
	//Loop through the Student Class and print out the information
	for (auto studItr = students.begin(); studItr<students.end(); studItr++) {
		studItr->printInfo();
		std::cout << "--------------------------" << std::endl;
	}
	std::cout << "\n" << std::endl;

	std::cout << "==== SEMINAR PROFESSORS INFO ====" << std::endl;
	//Create a vector of Professor, which contains all Professors from CS/MAT Seminar
	std::vector<Professor> professors;
	professors.push_back(Professor("Dr. Dostert", "123456789", "Assoc. Professor", "CS/MAT"));
	professors.push_back(Professor("Dr. Nguyen", "987654321", "Assoc. Professor", "MAT"));
	professors.push_back(Professor("Dr. Manspeaker", "456456789", "Assoc. Professor", "MAT"));
	professors.push_back(Professor("Dr. Zhang", "123456123", "Professor", "\tCS"));
	professors.push_back(Professor("Dr. Granger", "123456456", "Assoc. Professor", "MAT"));

	//Loop through the Professor Class and print out the information
	for (auto profItr = professors.begin(); profItr<professors.end(); profItr++) {
		profItr->printInfo();
		std::cout << "--------------------------" << std::endl;
	}
	
	std::cout << "\n" << std::endl;

	//Print out this information using a separate function
	printRoster(professors, students);

	system("pause");
	return(0);
}