#include "tasklist.h"
#include "tools.h"


//default constructor
TaskList::TaskList() {

	head = NULL;
	tail = NULL;
}
//constructor from file
TaskList::TaskList(const char fileName[]) {

	ifstream fin;
	Task aList;
	char tempName[MAXCHAR], tempDate[MAXCHAR], tempDescription[MAXCHAR];
	int tempQty = 0;
	head = NULL;
	tail = NULL;

	fin.open(fileName);
	if (!fin) {

		cout << "File not found! Closing" << endl;
		exit(0);
	}

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

	Node *curr = head;
	while (head) {

		head = curr->next;
		delete curr;
		curr = head;
	}
	head = NULL;
	curr = NULL;
}
//adds a task to list
void TaskList::addTask(Task &aTask) {

	char tempName1[MAXCHAR], tempName2[MAXCHAR];
	Node * newNode, *curr, *prev;

	newNode = new Node;
	newNode->data = aTask;
	newNode->next = NULL;

	//check if list exits
	if (!head) {

		head = newNode;
		tail = newNode;
	}
	else {

		curr = head;
		prev = NULL;
		curr->data.getName(tempName1);
		newNode->data.getName(tempName2);
		while (curr && strcmp(tempName1, tempName2) < 0)
		{
			prev = curr;
			curr = curr->next;
			if (curr)
				curr->data.getName(tempName1);
		}
		if (!curr)			//we are at the end of the list, so add to tail
		{
			tail->next = newNode;
			tail = newNode;
		}
		else
		{
			//insert between 2 nodes
			if (prev)
			{
				prev->next = newNode;
				newNode->next = curr;
			}
			else
			{
				newNode->next = head;
				head = newNode;
			}
		}
	}
}

const void TaskList::displayList() {

	Node *curr;
	for (curr = head; curr; curr = curr->next)
	{
		cout << curr->data;
	}
	cout << '\n';
}

//finds a task in the list
const void TaskList::findTask() {

	Node * curr;
	char srchTitle[MAXCHAR], tempName[MAXCHAR];
	
	cout << "Enter the movie you are looking for:";
	cin.get(srchTitle, MAXCHAR, '\n');
	convertCase(srchTitle);
	for (curr = head; curr; curr = curr->next)
	{
		curr->data.getName(tempName);
		convertCase(tempName);
		if (strstr(tempName, srchTitle))
		{
			cout << curr->data;
		}
	}
	cout << endl;
}

//writes the data back to the file
void TaskList::writeFile() {

	Node * curr;
	ofstream fout;
	
	fout.open("tasks.txt");
	if (!fout) {
		
		cout << "File not found! Closing" << endl;
		exit(0);
	}
	for (curr = head; curr; curr = curr->next)
	{
		curr->data.printFile(fout);
	}
	fout.close();
}

