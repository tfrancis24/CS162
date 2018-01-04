#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"
//consts
const int CAP = 100;
const int GROWTH = 3;


//class 
class TaskList {

private:
	Task *list;
	int size;
	int capacity;
public:
	//constructor
	TaskList();
	TaskList(const char fileName[]);
	//destructor
	~TaskList();
	//other list functions
	bool addTask(Task &aTask);
	const void displayList();
	const void findTask();
	void writeFile();
	void expandArray();
};

#endif