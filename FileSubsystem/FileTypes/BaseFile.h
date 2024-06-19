#pragma once
#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <ostream>

#include "../Utility/MyString.h"

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