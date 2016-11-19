#include "Student.h"
#include <iostream>
#include <iomanip> //For std::setw()

std::string Student::getNumber(void) {
	return this->_number;
}

void Student::setNumber(const std::string& number) {
	this->_number = number;
}

std::string Student::getName(void) {
	return this->_name;
}

void Student::setName(const std::string& name) {
	this->_name = name;
}

std::string Student::getAge(void) {
	return this->_age;
}

void Student::setAge(const std::string& age) {
	this->_age = age;
}

std::string Student::getGender(void) {
	return this->_gender;
}

void Student::setGender(const std::string& gender) {
	this->_gender = gender;
}

std::string Student::getType(void) {
	return this->_type;
}

void Student::setType(const std::string& type) {
	this->_type = type;
}

Student* Student::getNext(void) {
	return this->_next;
}

void Student::setNext(Student* next) {
	this->_next = next;
}

//Copy a student from another student
void Student::copyStudent(Student* destination, Student* source) {
	destination->setNumber(source->getNumber());
	destination->setName(source->getName());
	destination->setGender(source->getGender());
	destination->setAge(source->getAge());
	destination->setType(source->getType());

	return;
}

//Input a Student from a std::istream
void Student::input(std::istream& in) {
	//Read in the information
	in >> this->_number >> this->_name >> this->_gender >> this->_age >> this->_type;

	return;
}

//Output a Student to a std::ostream
void Student::output(std::ostream& out) {
	out << std::setw(10) << this->getNumber() << std::setw(10) << this->getName() << std::setw(6) << this->getGender() << std::setw(6) << this->getAge() << std::setw(20) << this->getType() << std::endl;

	return;
}
