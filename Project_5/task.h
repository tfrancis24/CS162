#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

//constants
const int MAXCHAR = 101;

//Class constructors and destructors
class Task {

	friend ostream& operator<< (ostream& out, const Task &);

private:
	char *name;
	char *description;
	char *date;
public:
	//constructors
	Task();
	Task(char newname[], char newDescription[], char newDate[]);
	Task(const Task &aTask);
	//destructor
	~Task();
	const void getName(char returnName[]);
	const void getDescription(char returnDescription[]);
	const void getDate(char returnDate[]);
	void setName(char newname[]);
	void setDescription(char newDescription[]);
	void setDate(char newDate[]);
	const void printTasks();
	const void printFile(ofstream &fout);
	//overloading operators
	const Task& operator= (const Task& aTask);
};
#endif
