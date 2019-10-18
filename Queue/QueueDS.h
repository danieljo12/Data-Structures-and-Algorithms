#pragma once
#include <string>

constexpr int arraySize{ 5 };

class QueueDT {
private:
	std::string stringArray[arraySize];
	int readNum;
	int writeNum;

public:
	QueueDT();

	// adds key to the collection
	void enqueue(std::string key);

	// removes and returns the least recently-added key
	std::string dequeue();

	// checks if the queue is empty
	bool empty();

	// prints the all of the items in the queue
	void printQueue();
};

// This queue was implemented using arrays as u can see. you can implemement queues using linkedlists 2 :)