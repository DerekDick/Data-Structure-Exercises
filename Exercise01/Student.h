#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>

class Student {
	// Data members
	std::string _number;
	std::string _name;
	std::string _gender;
	std::string _age;
	std::string _type;
	Student* _next;

public:
	// Function members
	Student() = default;
	~Student() = default;

	std::string getNumber(void);
	void setNumber(const std::string& number);
	std::string getName(void);
	void setName(const std::string& name);
	std::string getGender(void);
	void setGender(const std::string& gender);
	std::string getAge(void);
	void setAge(const std::string& age);
	std::string getType(void);
	void setType(const std::string& type);
	Student* getNext(void);
	void setNext(Student* next);

	void input(std::istream& in);
	void output(std::ostream& out);

	static void copyStudent(Student* destination, Student* source);
};

#endif // _STUDENT_H_
