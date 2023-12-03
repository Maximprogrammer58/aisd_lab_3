#ifndef LAB_3_INCLUDE_USER_H
#define LAB_3_INCLUDE_USER_H

#include <iostream>
#include <string>
#include <vector>

class User {
	std::string name_;
	size_t age_;

public:
	User() : name_(""), age_(0) {}

	User(std::string name, size_t age) : name_(name), age_(age) {}

	User(const User& other) {
		name_ = other.name_;
		age_ = other.age_;
	}

	std::string getName() const {
		return name_;
	}

	size_t getAge() const {
		return age_;
	}

	bool operator==(const User& other) const {
		return ((name_ == other.name_) && (age_ == other.age_));
	}

	bool operator<(const User& other) const {
		return ((name_ < other.name_) || ((name_ == other.name_) && (age_ < other.age_)));
	}

	bool operator>=(const User& other) const {
		return ((name_ >= other.name_) || ((name_ == other.name_) && (age_ >= other.age_)));
	}

	bool operator<=(const User& other) const {
		return ((name_ <= other.name_) || ((name_ == other.name_) && (age_ <= other.age_)));
	}

	bool operator>(const User& other) const {
		return ((name_ > other.name_) || ((name_ == other.name_) && (age_ > other.age_)));
	}
};

std::ostream& operator<<(std::ostream& stream, const User& user)
{
	stream << "(" << user.getName() << ", " << user.getAge() << ")";
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