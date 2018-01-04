//This program tests the lab 5 functions
//Tim Francis
//Lab 5
//Sources: none

#include <iostream>
#include <cstring>

using namespace std;

struct Student {

	char * name;
	float gpa;
};

//functions
Student * createStudent(const char name[], float gpa);
bool destroyStudent(Student * aStudent);

//main
int main() {

	return 0;
}

Student * createStudent(const char name[], float gpa) {
	
	Student * aStudent = new Student;
	aStudent->name = new char[strlen(name) + 1];
	strcpy_s(aStudent->name, strlen(name) + 1, name);
	aStudent->gpa = gpa;

	return aStudent;
}

bool destroyStudent(Student * aStudent) {

	if (aStudent) {

		cout << "Is true" << endl;
		delete[] aStudent->name;
		delete aStudent; //delete obj
		aStudent = nullptr; //sets to nullptr
		return true;
	}

	cout << "False" << endl;
	return false;
	
}
