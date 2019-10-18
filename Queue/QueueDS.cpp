#include "QueueDS.h"
#include <iostream>

QueueDT::QueueDT() : writeNum(0), readNum(0) {}

void QueueDT::enqueue(std::string key)
{
	if (writeNum == readNum - 1) {
		// error
		std::cout << "Cannot do that, dequeue something\n";
	}
	else if (writeNum == arraySize - 1) {
		stringArray[writeNum] = key;
		writeNum = 0;
	}
	else {
		stringArray[writeNum] = key;
		writeNum++;
	}
}

std::string QueueDT::dequeue()
{
	if (readNum == arraySize - 1) {
		std::string value = stringArray[readNum];

		stringArray[readNum] = ""; // clears the slot in the array

		readNum = 0;

		return value;
	}
	else {
		std::string value = stringArray[readNum];

		stringArray[readNum] = ""; // clears the slot in the array

		readNum++;

		return value;
	}
}

bool QueueDT::empty()
{
	return readNum == writeNum;
}

void QueueDT::printQueue()
{
	std::string printValues;

	for (int i = 0; i < arraySize; i++) {
		printValues += stringArray[i] + ", ";
	}
	printValues += "\n";

	std::cout << printValues;
}

// below is what i did to test the queue :)
int main() {
	QueueDT ae{};

	ae.enqueue("a");
	ae.enqueue("b");
	ae.enqueue("c");

	std::cout << ae.dequeue() << "  aaaaaaaaaaaaaaa\n";

	ae.printQueue();

	std::cout << ae.dequeue() << "  aaaaaaaaaaaaaaa\n";

	ae.printQueue();

	ae.enqueue("d");
	ae.enqueue("e");
	ae.enqueue("f");

	ae.printQueue();

	ae.enqueue("g");

	ae.printQueue();

	std::cout << ae.dequeue() << "  aaaaaaaaaaaaaaa\n";

	ae.printQueue();


	std::cout << ae.dequeue() << "  aaaaaaaaaaaaaaa\n";

	ae.printQueue();

	std::cout << ae.dequeue() << "  aaaaaaaaaaaaaaa\n";

	ae.printQueue();

	std::cout << ae.dequeue() << "  aaaaaaaaaaaaaaa\n";

	ae.printQueue();

	std::cout << ae.empty() << "aa\n"; // 1 ======== true. just reminding
}