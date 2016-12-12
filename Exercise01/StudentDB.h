#ifndef _STUDENT_D_B_H_
#define _STUDENT_D_B_H_

#include "Student.h"

class StudentDB {
	// Data members
	Student* _head;

public:
	StudentDB() = default;
	~StudentDB() = default;

	void addStudent(std::istream& in);
	void insertStudent(void);
	void deleteStudent(void);
	void searchStudent(void);
	void modifyStudent(void);
	void count(void);
};

#endif // _STUDENT_D_B_H_
