#ifndef LAB_3_INCLUDE_USER_H
#define LAB_3_INCLUDE_USER_H

#include <iostream>
#include <string>
#include <vector>

class User {
	std::string name;
	size_t age;

public:
	User(std::string name, size_t age) : name(name), age(age) {}

	User(const User& other) {
		name = other.name;
		age = other.age;
	}

	std::string get_name() const {
		return name;
	}

	size_t get_age() const {
		return age;
	}

	bool operator==(const User& other) const {
		return ((name == other.name) && (age == other.age));
	}

	bool operator<(const User& other) const {
		return ((name < other.name) || ((name == other.name) && (age < other.age)));
	}

	bool operator>=(const User& other) const {
		return ((name >= other.name) || ((name == other.name) && (age >= other.age)));
	}
};

std::ostream& operator<<(std::ostream& stream, const User& user)
{
	stream << "(" << user.get_name() << ", " << user.get_age() << ")";
	return stream;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec)
{
	for (const auto& el : vec)
		stream << el << " ";
	stream << std::endl;
	return stream;
}

#endif