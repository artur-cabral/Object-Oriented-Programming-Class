//------LAB 4_ClassArrays----------------------------------------
// Author: Artur Cabral
// Summary:
// Important Classes:
//---------------------------------------------------------------

#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
class Professor :public Person {
public:
	Professor(std::string name, std::string SSN, std::string title, std::string dept);
	~Professor();
	void printInfo();
	void changeTitle(const std::string &newTitle);
private:
	std::string title;
	std::string dept;
};
//constructor
Professor::Professor(std::string namey, std::string SSNy, std::string titley, std::string depty) : Person(namey, SSNy) {
	title = titley; dept = depty;

}
//destructor
Professor::~Professor() {};
//
//
void Professor::printInfo() {
	Person::printInfo();
	std::cout << "Title:" << title << std::endl;
	std::cout << "Dept:" << dept << std::endl;
}
void Professor::changeTitle(const std::string &newTitle) {
	title = newTitle;
}

void printRoster(Person theProf, Student *theStudents[]) {
	//print professors name:
	std::cout << "Instructor: ";
	theProf.getName();
	std::cout << "\nClass Roster\n";
	std::cout << "NAME\t\t\t\tMAJOR\tSID\n";
	for (int i = 0; i < 9; i++) {
		std::cout << theStudents[i]-> getName()<< "\t\t\t" << theStudents[i]->getMajor() << "\t" << theStudents[i]->getSID() << std::endl;
	}
}
int maximum(int a, int b) {
	//(a > b ? a : b);
	if (a > b)
		return(a);
	return(b);
}

double maximum(double a, double b) {
	//(a > b ? a : b);
	if (a > b)
		return(a);
	return(b);
}
template <typename T> T minimum(T a, T b) {
	if (a < b)
		return(a);
	return(b);
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
	//std::cout << minimum<char>() << std::endl;
	//std::cout << "max of 3.0 and 4.5: " << maximum(3.0, 4.5)<< std::endl;
	//Person yelnick("Yelnick Mcwawa", "12345679");
	//Person henderson("Henderson Henry");
	/*Professor drLove("Dr Love", "999887777", "Asst Professor", "cs");
	Person yelnick("Yelnick Mcwawa", "12345679");
	Student crappyStudent("Stink McStinkers", "000111222", "BA", "1234566","JR");
	Person *myPeople[3] = { &drLove,&yelnick,&crappyStudent };
	for (int i = 0; i < 3; i++)
		myPeople[i]->printInfo();
	crappyStudent.setSSN("111002345");
	for (int i = 0; i < 3; i++)
		myPeople[i]->printInfo();*/
system("pause");
return(0);
}

/*

Person myPerson("Foo Bar", "655478963");
Student myStudent("Jan Doe", "147258369", "CHEM", "0234156", "JR");

// We've defined Person and Student as datatypes (like in, double, float, char, std::sting)

Student *myStudents[3];
myStudents[0] = new Student("Jan Doe", "147258369", "CHEM", "0234156", "JR");
myStudents[1] = new Student("Mika Doe", "147258334", "MATH", "0234154", "SR");

for (int i = 0; i < 2; i++) {
myStudents[i]->printInfo();

std::cout << "---------------------------------------" << std::endl;

}
Person *myPeeps[3];
myPeeps[0] = new Person("Doe John", "000111222333");
myPeeps[1] = new Person("Doe Doe", "000222333444");
// keeping the "Person Only" information for myStudents[0] (Jan) and throwing out the student information
myPeeps[2] = myStudents[0];
for (int i = 0; i < 3; i++) {
myPeeps[i]->printInfo();

std::cout << "---------------------------------------" << std::endl;

}
myPeeps[1]->setName("DoDo");
myPeeps[1]->printInfo();
*/