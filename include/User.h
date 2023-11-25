#ifndef LAB_3_INCLUDE_SORTING_H
#define LAB_3_INCLUDE_SORTING_H

#include <string>

class User {
	std::string name;
	size_t age;

public:
	User(std::string name, size_t age) : name(name), age(age) {}

	User(const User& other) {
		name = other.name;
		age = other.age;
	}

	std::string name() const {
		return name;
	}

	size_t age() const {
		return age;
	}

	bool operator==(const User& other) const {
		return ((name == other.name) && (age == other.age));
	}

	bool operator>(const User& other) const {
		return ((name > other.name) || ((name == other.name) && (age > other.age)));
	}

	bool operator>=(const User& other) const {
		return ((name >= other.name) || ((name == other.name) && (age >= other.age)));
	}
};

#endif