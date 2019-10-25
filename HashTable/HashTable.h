#pragma once
#include "HashObject.h"

class HashTable {
public:

	HashTable(const int p_size);// sets the size of the table (array)
	~HashTable();

	// Add the given key and object to hash table. If key exists, update the value.
	void add(HashObject* p_object);

	// Returns true if the given key exists in the table
	bool exists(const std::string p_key);

	const std::string get(std::string p_key);

	void remove(std::string p_key);

private:
	int hash(std::string p_key);// the hash function that returns a number. This number is the spot where the value should go

	int m_size;
	HashObject* m_data;
};

/* Hash table




*/