#ifndef TOOLS_H
#define TOOLS_h

#include "tasklist.h"

//function prototypes
//int readInt(char prompt[]);
void displayMenu();
char readOption();
void exeCmd(char option, TaskList &store);
void addTask(Task &aTask);
void convertCase(char tempStr[]);

#endif