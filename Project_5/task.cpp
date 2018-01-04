#include "task.h"


Task::Task() {

	//allocate memory
	name = new char[MAXCHAR];
	strcpy(name, "null");
	description = new char[MAXCHAR];
	strcpy(description, "null");
	date = new char[MAXCHAR];
	strcpy(date, "null");
}

//constructor with parameters
Task::Task(char newname[], char newDescription[], char newDate[]) {

	name = new char[strlen(newname) + 1];
	strcpy(name, newname);
	description = new char[strlen(newDescription) + 1];
	strcpy(description, newDescription);
	date = new char[strlen(newDate) + 1];
	strcpy(date, newDate);
}

//Copy Constructor
Task::Task(const Task &aTask) {

	name = new char[strlen(aTask.name) + 1];
	strcpy(name, aTask.name);
	description = new char[strlen(aTask.description) + 1];
	strcpy(description, aTask.description);
	date = new char[strlen(aTask.date) + 1];
	strcpy(date, aTask.date);
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

	strcpy(returnName, name);
}
const void Task::getDescription(char returnDescription[]) {

	strcpy(returnDescription, description);
}
const void Task::getDate(char returnDate[]) {

	strcpy(returnDate, date);
}

//mutator functions
void Task::setName(char newname[]) {
	
	if (name) {

		delete[] name;
		name = NULL;
	}
	name = new char[strlen(newname) + 1];
	strcpy(name, newname);
}

void Task::setDescription(char newDescription[]) {

	if (description) {

		delete[] description;
		description = NULL;
	}
	description = new char[strlen(newDescription) + 1];
	strcpy(description, newDescription);
}
void Task::setDate(char newDate[]) {

	if (date) {

		delete[] date;
		date = NULL;
	}
	date = new char[strlen(newDate) + 1];
	strcpy(date, newDate);
}

//print function to screen
const void Task::printTasks() {

	cout << name << ';' << description << ';' << date << endl;
}

//print function to file
const void Task::printFile(ofstream &fout) {

	fout << name << ';' << description << ';' << date << endl;
}

const Task& Task::operator= (const Task& aTask) {

	if (this == &aTask)
		return *this;
	//make current object *this a copy of the passed in student
	else
	{
		
		strcpy(this->name, aTask.name);
		strcpy(this->description, aTask.description);
		strcpy(this->date, aTask.date);
		return *this;
	}
}

ostream& operator<< (ostream& out, const Task& aTask) {
		
	out << aTask.name << ';' << aTask.description << ';' << aTask.date << endl;
		return out;	
}
