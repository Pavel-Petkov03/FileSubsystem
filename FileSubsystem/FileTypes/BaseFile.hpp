#pragma once
#include <chrono>
#include <iostream>
#include "../Auth/User.hpp"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <ostream>
#pragma warning(disable: 4996)
class BaseFile {
protected:
	MyString creationDate;
	MyString modificationDate;
	MyString name;
	BaseFile* parent;
	MyString getCurrentDateTime() const;
	MyString getPathRecurse(const BaseFile* current) const;

	void setModificationDate();
public:
	virtual ~BaseFile() = default;
	virtual BaseFile* clone() const = 0;
	BaseFile() = default;
	BaseFile(const MyString& name, BaseFile* parent);
	friend std::ostream& operator<<(std::ostream& ofs, const BaseFile&);
	MyString getPath() const;

	friend class Directory;

	friend class CdCommand;
	friend class LsCommand;
	friend class FindCommand;
	friend class TouchCommand;
};


MyString BaseFile::getCurrentDateTime() const
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm* now_tm = std::localtime(&now_time_t);
	std::stringstream ss;
	ss << std::put_time(now_tm, "%Y %m %d %H %M");
	return MyString(ss.str().c_str());
}

MyString BaseFile::getPathRecurse(const BaseFile* current) const
{
	if (!current->parent) {
		return MyString("root");
	}
	MyString result = getPathRecurse(current->parent);
	result += "/";
	result += current->name;
	return result;
}

void BaseFile::setModificationDate()
{
	this->modificationDate = getCurrentDateTime();
	std::cout << "Change modification date for " << name << std::endl;
}

BaseFile::BaseFile(const MyString& name, BaseFile* parent)
{
	this->creationDate = getCurrentDateTime();
	this->modificationDate = getCurrentDateTime();
	this->name = name;
	this->parent = parent;
}

MyString BaseFile::getPath() const
{
	return getPathRecurse(this); 
}

std::ostream& operator<<(std::ostream& ofs, const BaseFile& file)
{
	ofs << file.creationDate << std::endl;
	ofs << file.modificationDate << std::endl;
	ofs << file.name << std::endl;
	return ofs;
}