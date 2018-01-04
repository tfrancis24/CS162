#include<iostream>
#include<cstring>

using namespace std;

//const
const int MAX_CHAR = 100;

struct Student {

	char id[MAX_CHAR];
	float gpa;

};

const int MAX_CAP = 10;

//class
class StudentList {

public:

	StudentList();
	int search(const char id[], Student &match) const;
	bool get(int index, Student &aStudent) const;
	bool remove(const char id[], Student &aStudent);

private:

	Student list[MAX_CAP];
	int size;

};

//Functions
StudentList::StudentList() {

	//list[MAX_CAP] = initList[MAX_CAP];


}


int StudentList::search(const char id[], Student &match) const {

	cin.get(id, MAX_CHAR, '\n'); //problem line
	for (int i = 0; i < size; i++) {

		if (strcmp(list[i].id, id) == 0) {
			cout << "Match" << endl; //test
			match = list[i];
			return i;

		} else {
			cout << "Error" << endl; //test
			return -1;
		
		}

	}
	cout << endl;
}

bool StudentList::get(int index, Student &aStudent) const {

	if (index < 0 || index > size) {

		return false;
	
	} else {

		aStudent = list[index];
		return true;
	
	}

}

bool StudentList::remove(const char id[], Student &aStudent) {
	int i = 0;
	for (i; i < size; i++) {
		
		if (strcmp(list[i].id, id) == 0) {
			
			aStudent = list[i];
		
		} else {
		
			return false;

		}
	}

	for (int j = i - 1; j < size; j++) {
	
		list[j] = list[j + 1];
		return true;

	}
	//for loop to find position
	//use example for loop and var j

}


//main
int main() {

	//vars
	Student aStudent;
	strcpy_s(aStudent.id, "bob");
	aStudent.gpa = 4.0;
	StudentList aStudentList;
	
	aStudentList.search("bob", aStudent);
	aStudentList.get(0, aStudent);
	aStudentList.remove("bob", aStudent);

	

	return 0;

}


