#include <iostream>
#include "BaseFile.h"

BaseFile::BaseFile(std::chrono::system_clock::time_point& creationDate, std::string name, const User& creator, BaseFile* parent)
{
	this->creator = &creator;
	this->creationDate = creationDate;
	this->modificationDate = creationDate;
	this->name = name;
	this->parent = parent;
}
