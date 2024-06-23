#pragma once
#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <ostream>

#include "../Utility/MyString.h"


enum class FileTypes {
	DirectoryType = 0,
	ExeType = 1,
	TxtType = 2,
	LinkType = 3,
};

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
	virtual FileTypes getType() const = 0;
	BaseFile() = default;
	BaseFile(const MyString& name, BaseFile* parent);
	friend std::ostream& operator<<(std::ostream& ofs, const BaseFile&);
	friend std::istream& operator>>(std::istream& ofs, BaseFile&);
	MyString getPath() const;
	virtual void serialise(std::ostream& ofs) const = 0;
	virtual void deserialise(std::istream& ifs) = 0;

	friend class MyString;
	friend class Directory;

	friend class CdCommand;
	friend class LsCommand;
	friend class FindCommand;
	friend class TouchCommand;
	friend class RemoveFileCommand;
};