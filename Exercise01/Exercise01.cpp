#include <iostream>
#include "Student.h"
#include "StudentDB.h"

void displayOptions(void);

int main(int argc, char* argv[]) {
	// Display the welcoming information
	std::cout << "***********************************" << std::endl;
	std::cout << "*           Exercise 01           *" << std::endl;
	std::cout << "*         考生报名管理系统        *" << std::endl;
	std::cout << "*          1552719 侯剑锋         *" << std::endl;
	std::cout << "***********************************" << std::endl;
	displayOptions();

	// Set up the initial database
	std::cout << "首先请建立考生信息系统！" << std::endl;
	StudentDB* studentDB = new StudentDB();
	int n = 0;
	std::cout << "请输入考生人数：" << std::endl;
	std::cin >> n;
	std::cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别（请以一个空格隔开各项）：" << std::endl;
	for (int i = 0; i < n; i++) {
		studentDB->addStudent(std::cin);
	}

	// Display the students that the user has just input
	std::cout << "您已经输入了如下数据：" << std::endl;
	studentDB->count();

	// Receive the user's choice and operate according to the choice in loops
	displayOptions();
	char choice = '\0';
	while (std::cin >> choice) {
		// Cancel
		if (choice == '0') {
			std::cout << "即将退出考试报名系统！" << std::endl;
			delete studentDB;
			break;
		}

		// Insert
		else if (choice == '1') {
			studentDB->insertStudent();
		}

		// Delete
		else if (choice == '2') {
			studentDB->deleteStudent();
		}

		// Search
		else if (choice == '3') {
			studentDB->searchStudent();
		}

		// Modify
		else if (choice == '4') {
			studentDB->modifyStudent();
		}

		// Count
		else if (choice == '5') {
			studentDB->count();
		}

		// Exceptions
		else {
			std::cout << "Illegal input!!!" << std::endl;
		}

		// Display the options for the next loop
		displayOptions();
	}

	return 0;
}

void displayOptions(void) {
	/* Display the options for the user */

	std::cout << "请选择您的操作（1-插入，2-删除，3-查找，4-修改，5-统计，0-取消操作）：" << std::endl;
}
