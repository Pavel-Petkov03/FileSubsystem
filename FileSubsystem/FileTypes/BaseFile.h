#pragma once
#include <chrono>
#include <iostream>
#include "../Auth/User.h"
class BaseFile {
private:
	std::chrono::system_clock::time_point  modificationDate;
	std::chrono::system_clock::time_point creationDate;
	std::string name;
	BaseFile* parent;
	const User* creator;
public:
	virtual ~BaseFile() = default;
	virtual BaseFile* clone() const = 0;
	BaseFile(std::chrono::system_clock::time_point& creationDate, std::string name, const User& creator, BaseFile* parent);
};