#pragma once
#include <string>

class HashObject {
public:
	HashObject& operator=(const HashObject&) = default;

	void setKey(const std::string p_key) { m_key = p_key; }

	void setValue(const std::string p_value) { m_value = p_value; }

	std::string& getKey() { return m_key; }

	std::string& getValue() { return m_value; }

	static const std::string getNullKey() { return "<Null>"; }

private:
	std::string m_key;
	std::string m_value;
};