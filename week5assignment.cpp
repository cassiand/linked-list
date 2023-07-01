// cassian
// 10/8/22
// create and implement a simple linked list with menu options to manipulate data
// module description: basics of linked lists and how to manipulate them


#include <iostream>
using namespace std;

typedef struct node { //declare and define struct to store node in

	char data;
	node* pNext;

}node;

class linkedList { // declare class

	node* pFirst; // pointer to first node
	static int no_of_node;

public:

	linkedList(); // constructor
	~linkedList(); //destructor

	void insert_node(int place, node* n); // function declarations
	void delete_node(int place);
	void display_list();
	bool find_node(char key);
};

int linkedList::no_of_node = 0;

linkedList::linkedList() { // function definition, first node empty

	pFirst = NULL;

}
linkedList::~linkedList() //destructor
{
	//deleting all nodes
	node* pTemp = pFirst;
	while (pTemp != NULL)
	{
		pFirst = pFirst->pNext;
		delete pTemp;
		pTemp = pFirst; // set back to first element
	}
}

void linkedList::insert_node(int place, node* n) { // function definition 

	if (place > no_of_node + 1) 
	{	// if you enter a place where the prev space isnt filled
		cout << "You entered an invalid place\n";
		return;
	}

	else 
	{																	// https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/ used for reference for																		
		if (place == 1)													// insertion and deletion
		{
			n->pNext = pFirst; //set to pFirst
			pFirst = n;
		}
		else 
		{
			node* pTemp = pFirst;
			place = place - 2; 
			while (pTemp->pNext && place--) 
			{
				pTemp = pTemp->pNext;
			}
			n->pNext = pTemp->pNext;
			pTemp->pNext = n;
		}
	}
	no_of_node++; // increment num of nodes
}

void linkedList::delete_node(int place) { // function definition

	node* pTemp = pFirst, * pre, * current;

	if (pFirst == NULL || place > no_of_node) // if the first spot is empty or the inputted place is greater than the num of nodes
	{ 
		cout << "\nInvalid place\n";
		return;
	}
	else
	{
		pre = pTemp;
		while (pTemp != NULL && place > 1)
		{
			place--;
			pre = pTemp;
			pTemp = pTemp->pNext;
		}
		if (pTemp == pFirst)
			pFirst = pFirst->pNext;
		else
		{
			pre->pNext = pTemp->pNext;
		}
		delete pTemp;
		no_of_node--;
	}
}

void linkedList::display_list() { // function definition

	node* pTemp = pFirst; // set ptr to first
	while (pTemp) 
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->pNext; // show each element
	}
}


bool linkedList::find_node(char key) {
	node* pTemp = pFirst;
	while (pTemp) 
	{
		if (pTemp->data == key)return true; //if matches
		pTemp = pTemp->pNext; // go to next to check
	}

	return false;
}

int main() {

	int choice, place; // declare variables for input
	node* new_node;
	char ch, key;
	linkedList myList; // declare obj of linkedList class

	do {

		// display menu
		cout << "\n1:Insert\n2:Delete\n3:Display\n4:Search\n5:Exit\n";
		cin >> choice; // get input
		switch (choice) {

		case 1: {cout << "Enter character you wish to add, as a capital letter: ";

			cin >> ch;
			if (ch < 'A' || ch>'Z') // if char isnt in alphabet
			{ 
				cout << "Invalid input\n";
				break;
			}

			cout << "Enter place: ";
			cin >> place; // get place to add item
			new_node = new node;

			new_node->data = ch; // set to input
			new_node->pNext = NULL; // declare next empty
			myList.insert_node(place, new_node); // add node

			break;
		}
		case 2: 
		{
			cout << "Enter a place to delete: ";
			cin >> place; // get place
			myList.delete_node(place); // call delete function
			break;
		}

		case 3: 
		{
			cout << "The linked list is:\n";
			myList.display_list(); // print list

			break;
		}

		case 4: {

			cout << "Enter key to be searched: ";
			cin >> key; // get key

			if (myList.find_node(key))cout << key << " was found\n"; // if key could be found

			else cout << key<<" was not found\n"; // otherwise

			break;
		}
		}
	} 
	while (choice != 5); // as long as user isn't exiting

	return 0;

}