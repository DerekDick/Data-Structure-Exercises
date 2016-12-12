#include "StudentDB.h"
#include <iostream>
#include <map>

// Adds a student at the end of the current linked list
void StudentDB::addStudent(std::istream& in) {
	// Read in the student
	Student* temp = new Student();
	temp->input(in);

	// Check if the number of the current student to be added already exists
	for (Student* current = this->_head; current; current = current->getNext()) {
		if (!current->getNumber().compare(temp->getNumber())) {
			std::cout << "已经存在相同考号的考生！" << std::endl;
			delete temp;
			return;
		}
	}

	// Add a student at the end of the single linked list
	if (!this->_head) {
		this->_head = new Student();
		Student::copyStudent(this->_head, temp);
	}
	else {
		Student* current = this->_head;
		while (current->getNext()) {
			current = current->getNext();
		}
		current->setNext(new Student());
		current = current->getNext();
		Student::copyStudent(current, temp);
	}
	delete temp;

	return;
}

// Inserts a student at a certain position
void StudentDB::insertStudent(void) {
	// Prompt the user to input the position of the insertion
	std::cout << "请输入您要插入的考生的位置（一个不超过已经输入学生数量的正整数）：" << std::endl;

	// Input a student
	int position = 0;
	std::cin >> position;
	Student* temp = new Student();
	std::cout << "请输入您要插入的考生的考号，姓名，性别，年龄及报考类别（请以一个空格隔开各项）：" << std::endl;
	temp->input(std::cin);

	// Check if the number of the current student to be added already exists
	for (Student* current = this->_head; current; current = current->getNext()) {
		if (!current->getNumber().compare(temp->getNumber())) {
			std::cout << "已经存在相同考号的考生！" << std::endl;
			delete temp;
			return;
		}
	}

	if (position == 1) {
		temp->setNext(this->_head);
		this->_head = temp;
		return;
	}
	Student* current = this->_head;
	for (int i = 0; i < position - 1; i++) {
		if (!current) {
			std::cout << "Illegal input!!!" << std::endl;
			std::cout << "超过已有考生数量！" << std::endl;
			delete temp;
			return;
		}
		current = current->getNext();
	}
	Student::copyStudent(current, temp);
	delete temp;

	return;
}

// Deletes a Student
void StudentDB::deleteStudent(void) {
	// Input the number of the Student to be deleted
	std::cout << "请输入您要删除的考生的考号：" << std::endl;
	std::string number = "";
	std::cin >> number;

	// Search and delete the Student
	Student* current = this->_head;
	while (current) {
		if (!current->getNumber().compare(number)) {
			Student* temp = this->_head;
			while (temp->getNext() != current) {
				temp = temp->getNext();
			}
			temp->setNext(current->getNext());
			delete current;
			return;
		}
		current = current->getNext();
	}
	std::cout << "未找到该考生！" << std::endl;

	return;
}

// Searches for a Student and print it
void StudentDB::searchStudent(void) {
	// Input the nubmer of the Student to be searched for
	std::cout << "请输入您要查找的考生的考号：" << std::endl;
	std::string number = "";
	std::cin >> number;

	// Searching...
	Student* current = this->_head;
	while (current) {
		if (!current->getNumber().compare(number)) {
			std::cout << "考号  姓名  性别  年龄  报考类别" << std::endl;
			current->output(std::cout);
			return;
		}
		current = current->getNext();
	}
	std::cout << "未找到该考生！" << std::endl;

	return;
}

// Modifies the information of a Student
void StudentDB::modifyStudent(void) {
	// Prompt the user to input the information of the Student to be modified
	Student* temp = new Student();
	std::cout << "请输入您要修改的考生的考号，姓名，性别，年龄及报考类别（请以一个空格隔开各项）：" << std::endl;
	temp->input(std::cin);

	// Search and modify the Student
	Student* current = this->_head;
	while (current) {
		if (!current->getNumber().compare(temp->getNumber())) {
			Student::copyStudent(current, temp);
			delete temp;
			return;
		}
		current = current->getNext();
	}
	std::cout << "未找到该考生！" << std::endl;
	delete temp;

	return;
}

// Prints the statistics of this database
void StudentDB::count(void) {
	Student* current = this->_head;
	int count = 0;
	std::cout << "      考号       姓名   性别   年龄             报考类别" << std::endl;
	while (current) {
		current->output(std::cout);
		count++;
		current = current->getNext();
	}
	std::cout << "学生数量：" << count << std::endl;
	
	// Display the number of the students of different types
	std::map<std::string, int> typeMap;
	current = this->_head;
	while (current) {
		typeMap[current->getType()]++;
		current = current->getNext();
	}
	std::cout << "不同类别的学生数量统计：" << std::endl;
	for (std::map<std::string, int>::iterator iter = typeMap.begin(); iter != typeMap.end(); iter++) {
		std::cout << '\t' << iter->first << ": " << iter->second << std::endl;
	}

	// Display the number of the male and female students and the male-female ratio
	int maleNumber = 0, femaleNumber = 0;
	double MFRatio = 0.0;
	current = this->_head;
	while (current) {
		std::string gender = current->getGender();
		if (gender == "男" || gender == "male" || gender == "Male" || gender == "MALE") {
			maleNumber++;
		}
		else {
			femaleNumber++;
		}
		current = current->getNext();
	}
	MFRatio = (double)maleNumber / (double)femaleNumber;
	std::cout << "男性数量： " << maleNumber << std::endl;
	std::cout << "女性数量： " << femaleNumber << std::endl;
	std::cout << "男女比例： " << MFRatio << " : 1" << std::endl;

	return;
}
