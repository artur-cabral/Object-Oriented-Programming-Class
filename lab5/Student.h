#pragma once
#include <string>
#include "Person.h"
//-----------Student Class--------------------------------------------------------------
//Student inherits the Person class, so by default, every data member and function
// member and function member in Person now exists in Student
// Author: Artur Cabral
//---------------------------------------------------------------------------------------
class Student : public Person {
public:
	Student(std::string namey, std::string SSNy, std::string majory, std::string SIDy, std::string yeary);
	~Student();
	void printInfo();
	void changeMajor(std::string newMajor);
	void changeYear(std::string newYear);
	void changeSID(std::string newSID);
	std::string getMajor();
	std::string getSID();
private:
	std::string major;
	std::string SID;
	std::string year;
};