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
	std::string creationDate;
	std::string modificationDate;
	std::string name;
	BaseFile* parent;
	std::string getCurrentDateTime() const;
	std::string getPathRecurse(const BaseFile* current) const;
public:
	virtual ~BaseFile() = default;
	virtual BaseFile* clone() const = 0;
	BaseFile(std::string name, BaseFile* parent);
	BaseFile() = default;
	friend std::ostream& operator<<(std::ostream& ofs, const BaseFile&);
	std::string getPath() const;

	friend class Directory;

	friend class CdCommand;
	friend class LsCommand;
	friend class FindCommand;
};


std::string BaseFile::getCurrentDateTime() const
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm* now_tm = std::localtime(&now_time_t);
	std::stringstream ss;
	ss << std::put_time(now_tm, "%Y %m %d %H %M");
	return ss.str();
}

std::string BaseFile::getPathRecurse(const BaseFile* current) const
{
	if (!current->parent) {
		return std::string("root");
	}
	return getPathRecurse(current->parent) + "/" + current->name;
}

BaseFile::BaseFile(std::string name, BaseFile* parent)
{
	this->creationDate = getCurrentDateTime();
	this->modificationDate = getCurrentDateTime();
	this->name = name;
	this->parent = parent;
}

std::string BaseFile::getPath() const
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