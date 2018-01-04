//This program will keep track of tasks from a txt file using classes
//Tim Francis
//Project3
//Sources: none

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>

using namespace std;

//consts
const int CAP = 100;
const int MAXCHAR = 101;

//Task Struct
struct Task {

	char taskName[MAXCHAR];
	char description[MAXCHAR];
	char date[MAXCHAR];

};

//class for the TaskList
class TaskList {

private:
	Task list[CAP];
	int size;
public:
	//constructor
	TaskList();
	TaskList(char fileName[]);
	//destructor
	~TaskList();
	bool addTask(const Task &aTask);
	const void TaskList::displayList();
	const void TaskList::searchList();
	void writeFile();

};

//function prototypes
void printMenu();
char readOption();
void exeResponse(char r, TaskList &store);
void convertCase(char temp[]);
void addTask(Task &aTask);

//functions
void printMenu() {

	cout << "\nWelcome to my Task List:" << endl;
	cout << "(a) to add a task" << endl;
	cout << "(s) to show the task list" << endl;
	cout << "(f) to find a task by course " << endl;
	cout << "(q) to quit" << endl;

}

char readOption() {

	char r; //response
	cin >> r;
	cin.ignore(100, '\n');
	return r;

}

void exeResponse(char r, TaskList &store) {

	Task aTask;
	switch (tolower(r)) {
		
	case 'a':
		addTask(aTask);
		if (store.addTask(aTask)) {
			cout << "Task added" << endl;
		} else {
			cout << "Duplicate task! Not added" << endl;
		}
		break;
	case 's':
		store.displayList();
		break;
	case 'f':
		store.searchList();
		break;
	case 'q':
		store.writeFile();
		break;
	default:
		cout << "Invalid input, try again" << endl;
	}

}

//populates aTask
void addTask(Task &aTask) {

	cout << "Enter a task";
	cin.get(aTask.taskName, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter a task description:";
	cin.get(aTask.description, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter a due date:";
	cin.get(aTask.date, MAXCHAR, '\n');
	cin.ignore(100, '\n');

}

void convertCase(char temp[]) {

	for (int i = 0; i < strlen(temp); i++) {
		
		temp[i] = toupper(temp[i]);
	
	}

}


TaskList::TaskList(){
	size = 0;
}

TaskList::TaskList(char fileName[]) {

	ifstream fin; //input file var
	Task aTask;
	
	fin.open(fileName);
	if (!fin) {
		cout << "Cant open file, closing!" << endl;
		exit(0);
	}
	size = 0;
	fin.get(aTask.taskName, MAXCHAR, ';');
	while (!fin.eof()) {
		fin.ignore(5, ';');
		fin.get(aTask.description, MAXCHAR, ';');
		fin.ignore(5, ';');
		fin.get(aTask.date, MAXCHAR, '\n');
		fin.ignore(5, '\n');
		addTask(aTask);
		fin.get(aTask.taskName, MAXCHAR, ';');
	
	}
	fin.close();
}

TaskList::~TaskList() {
	//destructor
}

bool TaskList::addTask(const Task &aTask) {

	int i = 0, j = 0;

	for (i = 0; i < size; i++) {
	
		if (strcmp(list[i].taskName, aTask.taskName) == 0)
			return false;

	}

	for (i = 0; i < size; i++) {

		if (strcmp(list[i].taskName, aTask.taskName) > 0)
			break;

	}

	for (j = size; j >= i; j--) {

		list[j + 1] = list[j];

	}

	list[i] = aTask;
	size++;
	return true;
}

//print the list
const void TaskList::displayList() {

	for (int i = 0; i < size; i++) {
		cout << i + 1 << ": " << list[i].taskName << ';' << list[i].description << ';' << list[i].date << '\n';
	}
	cout << '\n';
}
//search the list for a task
const void TaskList::searchList() {

	char search[MAXCHAR];

	cout << "Enter the task you are searching for:";
	cin.get(search, MAXCHAR, '\n');
	convertCase(search);
	for (int i = 0; i < size; i++) {
	
		convertCase(list[i].taskName);
		if (strstr(list[i].taskName, search)) {
		
			cout << list[i].taskName << ';' << list[i].description << ';' << list[i].date << '\n';
			
		}
	
	}
	cout << endl;
}
//writes to file when user wants to quit
void TaskList::writeFile() {

	ofstream fout;
	fout.open("tasks.txt");
	if (!fout) {
	
		cout << "File not found, closing" << endl;
		exit(0);

	}
	for (int i = 0; i < size; i++) {
	
		fout << list[i].taskName << ';' << list[i].description << ';' << list[i].date << '\n';
	
	}
	fout.close();
}

//main
int main() {

	TaskList store("tasks.txt");
	char r;
	do {
		
		printMenu();
		r = readOption();
		exeResponse(r, store);
	
	} while (tolower(r) != 'q');
	return 0;
}
