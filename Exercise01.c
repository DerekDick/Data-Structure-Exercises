#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char number[16];
	char name[32];
	char gender[8];
	char age[8];
	char type[32];
	Student* next;
};

Student* head;

void addStudent(void);
void insertStudent(void);
void deleteStudent(void);
void searchStudent(void);
void modifyStudent(void);
void count(void);
void inputStudent(Student* destination);
void printStudent(Student* student);
void copyStudent(Student* destination, Student* source);

int main(int argc, char* argv[]) {
	//Hello information
	printf("*************************\n");
	printf("*欢迎使用考试报名系统！ *\n");
	printf("*开发人员：侯剑锋1552719*\n");
	printf("*************************\n\n");
	printf("首先请建立考生信息系统！\n");

	//Set up the initial database
	int n = 0;
	printf("请输入考生人数：");
	scanf("%d", &n);
	printf("请依次输入考生的考号，姓名，性别，年龄及报考类别（请以一个空格隔开各项）：\n");
	for (int i = 0; i < n; i++) {
		addStudent();
	}

	//Display the students that the user has just input
	printf("您已经输入了如下数据：\n");
	count();

	//Receive the user's choice and operate according to the choice in loops
	printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）：\n");
	char choice = '\0';
	while (scanf(" %c", &choice)) {
		//Cancel
		if (choice == '0') {
			printf("即将退出考试报名系统！\n");
			break;
		}

		//Insert
		else if (choice == '1') {
			insertStudent();
			printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）：\n");
		}

		//Delete
		else if (choice == '2') {
			deleteStudent();
			printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）：\n");
		}

		//Search
		else if (choice == '3') {
			searchStudent();
			printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）：\n");
		}

		//Modify
		else if (choice == '4') {
			modifyStudent();
			printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）：\n");
		}

		//Count
		else if (choice == '5') {
			count();
			printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）：\n");
		}

		//Exceptions
		else {
			printf("Illegal input!!!\n");
			printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）：\n");
		}
	}

	return 0;
}

//Add a student at the end of the current linked list
void addStudent(void) {
	//Read in the student
	Student* temp = (Student*)calloc(1, sizeof(Student));
	inputStudent(temp);

	//Check if the number of the current student to be added already exists
	for (Student* current = head; current; current = current->next) {
		if (!strcmp(current->number, temp->number)) {
			printf("已经存在相同考号的考生！\n");
			free(temp);
			return;
		}
	}

	//Add a student at the end of the linked list
	if (!head) {
		head = (Student*)calloc(1, sizeof(Student));
		copyStudent(head, temp);
	}
	else {
		Student* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = (Student*)calloc(1, sizeof(Student));
		current = current->next;
		copyStudent(current, temp);
	}
	free(temp);

	return;
}

//Insert a student at a certain position
void insertStudent(void) {
	//Prompt the user to input the position of the insertion
	printf("请输入您要插入的考生的位置（一个不超过已经输入学生数量的正整数）：");
	
	//Input a student
	int position = 0;
	scanf("%d", &position);
	Student* temp = (Student*)calloc(1, sizeof(Student));
	printf("请输入您要插入的考生的考号，姓名，性别，年龄及报考类别（请以一个空格隔开各项）：\n");
	inputStudent(temp);

	//Check if the number of the current student to be added already exists
	for (Student* current = head; current; current = current->next) {
		if (!strcmp(current->number, temp->number)) {
			printf("已经存在相同考号的考生！\n");
			free(temp);
			return;
		}
	}

	if (position == 1) {
		temp->next = head;
		head = temp;
		return;
	}
	Student* current = head;
	for (int i = 0; i < position - 1; i++) {
		if (!current) {
			printf("Illegal input!!!\n");
			printf("超过已有考生数量！\n");
			free(temp);
			return;
		}
		current = current->next;
	}
	copyStudent(current, temp);
	free(temp);

	return;
}

//Input a Student
void inputStudent(Student* destination) {
	//Read in the information
	scanf("%s %s %s %s %s", destination->number, destination->name, destination->gender, destination->age, destination->type);

	return;
}

//Copy a Student from another Student
void copyStudent(Student* destination, Student* source) {
	strcpy(destination->number, source->number);
	strcpy(destination->name, source->name);
	strcpy(destination->gender, source->gender);
	strcpy(destination->age, source->age);
	strcpy(destination->type, source->type);

	return;
}

//Delete a Student
void deleteStudent(void) {
	//Input the number of the Student to be deleted
	printf("请输入您要删除的考生的考号：");
	char number[16] = "";
	scanf("%s", number);

	//Search and delete the Student
	Student* current = head;
	while (current) {
		if (!strcmp(current->number, number)) {
			Student* temp = head;
			while (temp->next != current) {
				temp = temp->next;
			}
			temp->next = current->next;
			free(current);
			return;
		}
		current = current->next;
	}
	printf("未找到该考生！\n");

	return;
}

//Search for a Student and print it
void searchStudent(void) {
	//Input the nubmer of the Student to be searched for
	printf("请输入您要查找的考生的考号：");
	char number[16] = "";
	scanf("%s", number);

	//Searching...
	Student* current = head;
	while (current) {
		if (!strcmp(current->number, number)) {
			printf("考号  姓名  性别  年龄  报考类别\n");
			printStudent(current);
			return;
		}
		current = current->next;
	}
	printf("未找到该考生！\n");

	return;
}

//Print the information of a Student
void printStudent(Student* student) {
	printf("%10s %10s %6s %6s %20s\n", student->number, student->name, student->gender, student->age, student->type);

	return;
}

//Modify the information of a Student
void modifyStudent(void) {
	//Prompt the user to input the information of the Student to be modified
	Student* temp = (Student*)calloc(1, sizeof(Student));
	printf("请输入您要修改的考生的考号，姓名，性别，年龄及报考类别（请以一个空格隔开各项）：\n");
	inputStudent(temp);

	//Search and modify the Student
	Student* current = head;
	while (current) {
		if (!strcmp(current->number, temp->number)) {
			copyStudent(current, temp);
			free(temp);
			return;
		}
		current = current->next;
	}
	printf("未找到该考生！\n");
	free(temp);

	return;
}

//Print all the students and count the number
void count(void) {
	Student* current = head;
	int count = 0;
	printf("      考号       姓名   性别   年龄             报考类别\n");
	while (current) {
		printStudent(current);
		count++;
		current = current->next;
	}
	printf("学生数量：%d\n", count);

	return;
}
