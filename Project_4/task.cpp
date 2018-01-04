#include "task.h"


Task::Task() {
	
	//allocate memory
	name = new char[MAXCHAR];
	strcpy_s(name, MAXCHAR, "null");
	description = new char[MAXCHAR];
	strcpy_s(description, MAXCHAR, "null");
	date = new char[MAXCHAR];
	strcpy_s(date, MAXCHAR, "null");
}

//constructor with parameters
Task::Task(char newname[], char newDescription[], char newDate[]) {
	
	name = new char[strlen(newname) + 1];
	strcpy_s(name, strlen(newname) + 1, newname);
	description = new char[strlen(newDescription) + 1];
	strcpy_s(description, strlen(newDescription) + 1, newDescription);
	date = new char[strlen(newDate) + 1];
	strcpy_s(date, strlen(newDate) + 1, newDate);
}
//Copy Constructor
Task::Task(const Task &aTask) {
	
	name = new char[strlen(aTask.name) + 1];
	strcpy_s(name, strlen(aTask.name) + 1, aTask.name);
	description = new char[strlen(aTask.description) + 1];
	strcpy_s(description, strlen(aTask.description) + 1, aTask.description);
	date = new char[strlen(aTask.date) + 1];
	strcpy_s(date, strlen(aTask.date) + 1, aTask.date);
}
//destructor
Task::~Task() {
	
	//deallocate memory
	if (name) {
		
		delete[] name;
		name = NULL;
	}
	if (description) {
		
		delete[] description;
		description = NULL;
	}
	if (date) {

		delete[] date;
		date = NULL;
	}
}


const void Task::getName(char returnName[]) {
	
	strcpy_s(returnName, MAXCHAR, name);
}
const void Task::getDescription(char returnDescription[]) {
	
	strcpy_s(returnDescription, MAXCHAR, description);
}
const void Task::getDate(char returnDate[]) {
	
	strcpy_s(returnDate, MAXCHAR, date);
}
//mutator functions
void Task::setName(char newname[]) {
	if (name) {
	
		delete[] name;
		name = NULL;
	}
	name = new char[strlen(newname) + 1];
	strcpy_s(name, strlen(newname) + 1, newname);
}
void Task::setDescription(char newDescription[]) {
	
	if (description) {

		delete[] description;
		description = NULL;
	}
	description = new char[strlen(newDescription) + 1];
	strcpy_s(description, strlen(newDescription) + 1, newDescription);
}
void Task::setDate(char newDate[]) {
	
	if (date) {

		delete[] date;
		date = NULL;
	}
	date = new char[strlen(newDate) + 1];
	strcpy_s(date, strlen(newDate) + 1, newDate);
}

//print function to screen
const void Task::printTasks() {
	
	cout << name << ';' << description << ';' << date << endl;
}

//print function to file
const void Task::printFile(ofstream &fout) {
	
	fout << name << ';' << description << ';' << date << endl;
}