#pragma once
#include <string>
//-------------Person Class-----------------------------
// Class Functions Declarations
// Author: Artur Cabral
//------------------------------------------------------
class Person {

public:
	Person(std::string initName, std::string initSSN);
	Person(std::string initName);
	~Person();
	virtual void printInfo();
	void setName(std::string newName);
	void setSSN(std::string setSSN);
	std::string getName();
	std::string getSSN();
private:
	std::string name;
	std::string SSN;

};