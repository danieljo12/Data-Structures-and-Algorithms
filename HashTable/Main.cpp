#include <iostream>
#include "HashTable.h"
#include "HashObject.h"

// used to test
int main() {
	std::cout << std::boolalpha;
	HashTable phoneBook(5); // hash table with 5 possible spots for values

	HashObject clodio;
	clodio.setKey("clodio");
	clodio.setValue("07324234242424342");

	HashObject mum;
	mum.setKey("mum");
	mum.setValue("07444444444444444444444");

	HashObject dad;
	dad.setKey("dad");
	dad.setValue("0788800088");

	phoneBook.add(&clodio);
	phoneBook.add(&mum);
	phoneBook.add(&dad);

	std::string phoneName;
	do {
		phoneName = "";

		// adds the hashObjects with the data to the hash table.
		std::cout << "Type the people that you want to get the number for : ";
		std::cin >> phoneName;

		std::cout << "\n" << phoneBook.get(phoneName) << "\n";
	} while (phoneName != "quit");

	std::string text;
	std::cout << "delete a key : ";

	std::cin >> text;
	std::cout << "exists? : " << phoneBook.exists(text) << "\n";
	phoneBook.remove(text);
	std::cout << "deleted \n";

	std::cout << "got : " << phoneBook.get(text) << "\n";
	std::cout << "exists? : " << phoneBook.exists(text);
}