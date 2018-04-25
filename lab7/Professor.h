#pragma once
#include <string>
#include "Person.h"
//-----------Professor Class--------------------------------------------------------------
//Professor inherits the Person class, so by default, every data member and function
// member and function member in Person now exists in Professor
// Author: Artur Cabral
//---------------------------------------------------------------------------------------
class Professor :public Person {
public:
	Professor(std::string name, std::string SSN, std::string title, std::string dept);
	~Professor();
	void printInfo();
	void changeTitle(const std::string &newTitle);
	std::string Professor::getDept();
	std::string Professor::getTitle();
private:
	std::string title;
	std::string dept;
};