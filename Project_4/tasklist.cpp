#include "tasklist.h"
#include "tools.h"


//default constructor
TaskList::TaskList() {
	
	capacity = CAP;
	list = new Task[capacity];
	size = 0;
}
//constructor from file
 TaskList::TaskList(const char fileName[]) {
	
	ifstream fin;
	Task aList;
	char tempName[MAXCHAR], tempDate[MAXCHAR], tempDescription[MAXCHAR];
	int tempQty = 0;
	fin.open(fileName);
	if (!fin) {
		
		cout << "File not found! Closing" << endl;
		exit(0);
	}
	capacity = CAP;
	list = new Task[capacity];
	size = 0;
	fin.get(tempName, MAXCHAR, ';');
	while (!fin.eof()) {
		
		fin.ignore(5, ';');
		fin.get(tempDescription, MAXCHAR, ';');
		fin.ignore(5, ';');
		fin.get(tempDate, MAXCHAR, '\n');
		fin.ignore(5, '\n');
		//populate aVideo with all the information
		aList.setName(tempName);
		aList.setDescription(tempDescription);
		aList.setDate(tempDate);
		this->addTask(aList);
		fin.get(tempName, MAXCHAR, ';');
	}
	fin.close();
}

//destructor
TaskList::~TaskList() {
	
	if (list) {
		
		delete[]list;
		list = NULL;
	}
}
//adds a task to list
bool TaskList::addTask(Task &aTask) {
	
	char tempName[MAXCHAR], tempDate[MAXCHAR], tempDescription[MAXCHAR];

	//check to expand
	if (size == capacity) {
		expandArray();
	}

	aTask.getName(tempName);
	list[size].setName(tempName);
	aTask.getDescription(tempDescription);
	list[size].setDescription(tempDescription);
	aTask.getDate(tempDate);
	list[size].setDate(tempDate);
	size++;
	return true;
}

const void TaskList::displayList() {
	
	for (int i = 0; i < size; i++) {
		
		list[i].printTasks();
	}
	cout << endl;
}

//finds a task in the list
const void TaskList::findTask() {
	
	char srchTitle[MAXCHAR], tempName[MAXCHAR];
	cout << "Enter the movie you are looking for:";
	cin.get(srchTitle, MAXCHAR, '\n');
	convertCase(srchTitle);
	for (int i = 0; i < size; i++) {
		
		list[i].getName(tempName);
		convertCase(tempName);
		if (strstr(tempName, srchTitle)) {
			list[i].printTasks();
		}
	}
	cout << endl;
}

//writes the data back to the file
void TaskList::writeFile() {
	
	ofstream fout;
	fout.open("tasks.txt");
	if (!fout) {
		cout << "File not found! Closing" << endl;
		exit(0);
	}
	for (int i = 0; i < size; i++) {
		list[i].printFile(fout);
	}
	fout.close();
}

void TaskList::expandArray()
{
	capacity += GROWTH;
	char tempName[MAXCHAR];
	char tempDescription[MAXCHAR];
	char tempDate[MAXCHAR];
	Task *tempList = new Task[capacity];
	for (int i = 0; i < size; i++)
	{
		list[i].getName(tempName);
		list[i].getDescription(tempDescription);
		list[i].getDescription(tempDate);
		tempList[i].setName(tempName);
		tempList[i].setDescription(tempDescription);
		tempList[i].setDate(tempDate);
	}
	delete[] list;
	list = tempList;
	tempList = NULL;
}
