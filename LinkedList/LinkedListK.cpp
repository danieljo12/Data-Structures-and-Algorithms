#include <iostream>

struct node
{
	int data;
	node* next;
};

class BLinkedlist
{
public:

	BLinkedlist() :size(0), head(nullptr) {}

	void push_front(int value) {
		node* newList = new node;
		newList->data = value;
		newList->next = head;// assigns the node called 'head' memory address to the 'next' pointer, so that the new node is linked to the old node

		head = newList;//assign's the memory address that newlist has to head so all of the data that you put into newList, head has it now

		// ^ this is what makes it push to the front because head is always at the front of the list.

		size++; // increments the size everytime this fucntion is called

	}

	void push_back(int value) {
		node* newList = new node;
		newList->data = value;
		newList->next = nullptr;

		if (head == nullptr) {
			head = newList;
			return;
		}

		node* current = head;

		while (current->next) { // loops up to the end.
			current = current->next;
		}

		// ^ this is usefull because it makes sure that it puts the node right at the back of the list. thats why this function is called push back

		current->next = newList; // assigns the memory address that 'newList' has to current's next pointer

		size++; // increments the size everytime this fucntion is called
	}

	void printLinkedList() {
		node* listHead = head;

		while (listHead != nullptr) {
			std::cout << "The id is " << listHead->data << std::endl;
			listHead = listHead->next;
		}
	}

	int listSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	~BLinkedlist() {
		std::cout << "Destroyed linkedlist";

		node* listHead = head;
		node* next = nullptr;

		while (listHead) {
			next = listHead->next; // gets the next node in the linkedlist and then assigns the memory address to 'next' node
			delete listHead; // deletes 'listHead'
			listHead = next;
		}
	}

private:
	int size;
	node* head;
};


int main() {

	BLinkedlist list{};

	list.push_front(32);
	list.push_front(123);


	list.printLinkedList();
}

// https://stackoverflow.com/questions/28905958/understanding-linked-list-in-c  <- good explaination on whats happening as a diagram :)