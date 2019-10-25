#include "HashTable.h"

HashTable::HashTable(const int p_size) {
	m_size = p_size;
	m_data = new HashObject[m_size];

	for (int i = 0; i < m_size; i++) {
		m_data[i].setKey(HashObject::getNullKey()); // sets the whole array to <Null>
	}
}

HashTable::~HashTable() { delete[] m_data; } // deletes the dynmatically allocated 'HashObject'

void HashTable::add(HashObject* p_object) {
	int index = hash(p_object->getKey());
	const int original_index = index;

	bool found = false;
	// This while loop checks if the index that was given by the hash function is in use. if it is it tryes to find a new spot nearby
	while (m_data[index].getKey() != HashObject::getNullKey()) {

		if (m_data[index].getKey() == p_object->getKey()) {
			found = true;
			break;
		}

		index = (index + 1) % m_size;
		if (index == original_index) {
			return;
		}

	}

	m_data[index].setKey(p_object->getKey());
	m_data[index].setValue(p_object->getValue());
}

bool HashTable::exists(const std::string p_key) {
	int index = hash(p_key);
	const int orginal_index = index;
	bool found = false;

	while (m_data[index].getKey() != HashObject::getNullKey()) {

		if (m_data[index].getKey() == p_key) {
			found = true;
			break;
		}

		index = (index + 1) % m_size;
		if (index == orginal_index) {
			break;
		}

	}

	return found;
}

const std::string HashTable::get(std::string p_key) {
	int index = hash(p_key);
	const int orginal_index = index;

	while (m_data[index].getKey() != HashObject::getNullKey()) {

		if (m_data[index].getKey() == p_key) { // found the index that has the key
			return m_data[index].getValue();
		}

		index = (index + 1) % m_size;
		if (index == orginal_index) {
			break;
		}

	}

	return "<null>";
}

void HashTable::remove(std::string p_key) {
	int index = hash(p_key);
	const int orginal_index = index;

	while (m_data[index].getKey() != HashObject::getNullKey()) {

		if (m_data[index].getKey() == p_key) {
			m_data[index].setKey(HashObject::getNullKey());
			m_data[index].setValue("");
			break;
		}

		index = (index + 1) % m_size;
		if (index == orginal_index) {
			break;
		}

	}

}

// the hash function that actually returns the spot where the key / value will be located in the array
int HashTable::hash(std::string p_key) {
	int hash = 0;

	int key_length = static_cast<int>(p_key.length());
	for (int i = 0; i < key_length; ++i) {
		hash = hash * 31 + p_key[i];
	}

	return abs(hash % m_size);
}
