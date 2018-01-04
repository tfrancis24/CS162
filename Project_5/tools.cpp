//Implementation File
#include "tools.h"

//displays the menu
void displayMenu() {

	cout << "Choose a task:" << endl << endl;
	cout << "A: Add a task" << endl;
	cout << "D: Display the list" << endl;
	cout << "F: Find a task" << endl;
	cout << "Q: Quit the program" << endl;
}

//read the option from the user
char readOption() {

	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

//chooses correct function
void exeCmd(char option, TaskList &store) {

	Task aTask;
	switch (tolower(option)) {

	case 'a':
		addTask(aTask);
		store.addTask(aTask);
		break;
	case 'd':
		store.displayList();
		break;
	case 'f':
		store.findTask();
		break;
	case 'q':
		store.writeFile();
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
}

//populate aTask from the user
void addTask(Task &aTask) {

	char tempTitle[MAXCHAR], tempDescription[MAXCHAR], tempDate[MAXCHAR];

	cout << "Enter a task name:";
	cin.get(tempTitle, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter the task description:";
	cin.get(tempDescription, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter the due date:";
	cin.get(tempDate, MAXCHAR, '\n');
	cin.ignore(100, '\n');

	//populate aTask
	aTask.setName(tempTitle);
	aTask.setDescription(tempDescription);
	aTask.setDate(tempDate);
	cout << "Task added" << endl;
}

//converts all text to upper case
void convertCase(char tempStr[]) {

	for (int i = 0; i < strlen(tempStr); i++) {

		tempStr[i] = toupper(tempStr[i]);
	}
}
