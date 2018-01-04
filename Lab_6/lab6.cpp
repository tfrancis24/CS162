#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//struct
struct Student {

	char * name;
	float gpa;
};

//prototypes
Student ** createStudentList(char ** names, int size);
bool destroyStudentList(Student ** studentList, int size);

//main
int main() {

	ifstream fin;
	Student ** aStudent = new Student *;
	*aStudent = new Student;
	int rows = 10, i = 0;
	char ** names, tempName[999];
	fin.open("test.txt");
	names = new char *[rows];
	
	aStudent = createStudentList(names, 0);

	while (!fin.eof())
	{
		fin.getline(tempName, 31);
		names[i] = new char[strlen(tempName) + 1];
		strcpy_s(names[i], strlen(tempName) + 1, tempName);
		i++;
	}
	fin.close();
	for (int i = 0; i < rows; i++)
	{
		cout << names[i] << endl;
	}
	destroyStudentList(aStudent, 0);

	return 0;
}

//functions
Student ** createStudentList(char ** names, int size) {

	Student ** studentList;
	studentList = new Student*[size];

	for (int i = 0; i < size; i++) {

		//create mem
		studentList[i] = new Student;
		studentList[i]->name = new char[strlen(names[i]) + 1];
		//point to something
		strcpy(studentList[i]->name, names[i]);
		studentList[i]->gpa = 0;
	}

	cout << "Creating stuff" << endl;
	return studentList;
}

bool destroyStudentList(Student ** studentList, int size) {

	if (studentList) {

		for (int i = 0; i < size; i++) {

			//deletes name and obj, then assigns nullptr
			delete[] studentList[i]->name;
			delete studentList[i];
			studentList[i]->name = nullptr;
			studentList[i] = nullptr;
		}
		cout << "Is true, deleting" << endl;
		return true;
	}

	cout << "Is false, did not delete anything" << endl;
	return false;
}
