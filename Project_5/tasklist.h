#ifndef TASKLIST_H
#define TASKLIST_H

#include <cstring>
#include <cstdlib>
#include "task.h"


//class
class TaskList {

private:
	struct Node {

		Task data;
		Node * next;
	};
	Node *head, *tail;

public:
	//constructor
	TaskList();
	TaskList(const char fileName[]);
	//destructor
	~TaskList();
	//other list functions
	void addTask(Task &aTask);
	const void displayList();
	const void findTask();
	void writeFile();
	//void expandArray();
};

#endif

