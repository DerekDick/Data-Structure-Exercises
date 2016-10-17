#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

Student* head = NULL;
Student* previous = NULL;
Student* current = NULL;

void addStudent(void);
void printStudent(Student* student);
void printDataBase(void);
void insertStudent(void);
void deleteStudent(void);

struct Student {
	char number[16] = "";
	char name[32] = "";
	char gender[16] = "";
	char age[3] = "";
	char type[32] = "";

	Student* next = NULL;
};

int main(int argc, char* argv[]) {
	//Input the initial information of students
	int n = 0;
	printf("首先请建立考生信息系统！\n请输入考生人数：");
	scanf("%d", &n);
	printf("请依次输入考生的考号，姓名，性别，年龄及报考类别！\n");
	head = current = (Student*)calloc(1, sizeof(Student));
	for (int i = 0; i < n; i++) {
		addStudent();
	}

	//Accept the choice of the user and operate
	int choice = 0; //The choice of the user, 1 for insertion, 2 for deletion, 3 for searching, 4 for modification, 5 for statistics and 0 for cancellation
	printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计0为取消操作）：\n");
	scanf("%d", &choice);
	while (choice) {
		switch (choice) {
			//Insertion
		case 1:
			insertStudent();
			break;
			//Deletion
		case 2:
			deleteStudent();
			break;
			//Searching
		case 3:

			break;
			//Modification
		case 4:

			break;
			//Statistics
		case 5:
			printDataBase();
			break;
		}

		printf("请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计0为取消操作）：\n");
		scanf("%d", &choice);
	}

	return 0;
}

void addStudent(void) {
	/*Add a student at the current point*/
	scanf("%s", current->number);
	scanf("%s", current->name);
	scanf("%s", current->gender);
	scanf("%s", current->age);
	scanf("%s", current->type);
	previous = current;
	current = (Student*)calloc(1, sizeof(Student));
	previous->next = current;

	return;
}

void printStudent(Student* student) {
	/*Print out the information of the student*/
	printf("%-8s", student->number);
	printf("%-10s", student->name);
	printf("%-6s", student->gender);
	printf("%-6s", student->age);
	printf("%-20s", student->type);
	printf("\n");

	return;
}

void printDataBase(void) {
	/*Print out all the students in the data base*/
	printf("考号    姓名      性别  年龄  报考类别\n");
	current = head;
	do {
		printStudent(current);
		current = current->next;
	} while (current->next);

	return;
}

void insertStudent() {
	/*Insert a student at the specified position*/
	//Promopt user
	int index = 0;
	printf("请输入您要插入的考生的位置：\n");
	scanf("%d", &index);

	//Input the new student
	Student* newStudent = (Student*)calloc(1, sizeof(Student));
	printf("请依次输入考生的考号，姓名，性别，年龄及报考类别！\n");
	scanf("%s", newStudent->number);
	scanf("%s", newStudent->name);
	scanf("%s", newStudent->gender);
	scanf("%s", newStudent->age);
	scanf("%s", newStudent->type);

	//Organise the data base
	if (index <= 0) {
		printf("Illegal input!(The insetion index must be a positive integer!\n)");
		return;
	}
	else if (index - 1) {
		current = head;
		for (int i = 0; i < index - 2; i++) {
			current = current->next;
		}
		newStudent->next = current->next;
		current->next = newStudent;
	}
	else {
		newStudent->next = head;
		head = newStudent;
	}

	return;
}

void deleteStudent(void) {
	/*Delete a student at the specified position*/
	char number[16] = "";
	printf("请输入您要删除的考生的考号：\n");
	scanf("%s", number);

	//Find the student
	current = head;
	do {
		if (!strcmp(current->number, number)) {
			break;
		}
	} while (current->next);

	//Delete the student
	if (!current->next) {
		printf("不存在该考生！\n");
	}
	else if (!current->next->next) {
		strcpy(current->number, "");
		strcpy(current->name, "");
		strcpy(current->gender, "");
		strcpy(current->age, "");
		strcpy(current->type, "");
		free(current->next);
		current->next = NULL;
	}
	else {
		if (current == head) {
			head = current->next;
			free(current);
		}
		else {

		}
	}

	return;
}
