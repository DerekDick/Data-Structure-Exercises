#include "Student.h"
#include <iostream>
#include <iomanip>

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

void Student::copyStudent(Student* destination, Student* source) {
	/* Copies a student from another student */

	destination->setNumber(source->getNumber());
	destination->setName(source->getName());
	destination->setGender(source->getGender());
	destination->setAge(source->getAge());
	destination->setType(source->getType());

	return;
}

void Student::input(std::istream& in) {
	/* Inputs a Student from a std::istream */

	// Read in the information
	in >> this->_number >> this->_name >> this->_gender >> this->_age >> this->_type;

	return;
}

void Student::output(std::ostream& out) {
	/* Outputs a Student to a std::ostream */

	out << std::left << std::setw(10) << this->getNumber() << std::setw(11) << this->getName() << std::setw(7) << this->getGender() << std::setw(7) << this->getAge() << std::setw(21) << this->getType() << std::endl;

	return;
}
