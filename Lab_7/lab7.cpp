#include <iostream>
#include <cstring>

using namespace std;

struct Student {

	char * name;
	float gpa;
};

class StudentList {

public:

	bool remove(const char name[], Student& aStudent);
	void findHighestGpa(Student& aStudent) const;
	bool get(int index, Student& aStudent) const;


private:

	struct Node {

		Student data;
		Node * next;
	};

	Node * head;
	int size;
};



int main() {

	return 0;
}

bool StudentList::remove(const char name[], Student& aStudent) {

	Node *newNode = NULL, *curr =  NULL, *prev = NULL, *tail = NULL;

	while (curr && strcmp(curr->data.name, name) < 0) {
	
		prev = curr;
		curr = curr->next;
	}
	if (!curr) {
		
		tail->next = newNode;
		tail = newNode;
	} else {
	
		if (!prev) {
			
			prev->next = curr->next;
		} else {

			head = curr->next;
		}
		delete curr;
		return true;
	}

	return false;
}

void StudentList::findHighestGpa(Student& aStudent) const {
	
	Node * curr = head, * prev = NULL;
	int max = curr->data.gpa;
	
	for (curr = head; curr; curr = curr->next) {
		
		if (curr->data.gpa > max) {
			
			max = curr->data.gpa;
		}
	}
	
}

bool StudentList::get(int index, Student& aStudent) const {

	Node * curr = head, *prev = NULL;
	 int i = 0;

	for (curr = head; curr; curr = curr->next)
	{
		i++;
		if (i == index) {
		
			aStudent = curr->data;
			return true;
		}
	}

	return false;
}

