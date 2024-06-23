#pragma once

#include "../../BaseFile.h"
#include "../../../Auth/headers/User.h"
#include "../../../Errors/FileErrors.hpp"


class ExecutableFile : public BaseFile {
protected:
	Vector<MyString> fileLines;
	bool executed = false;

public:
	ExecutableFile() = default;
	ExecutableFile(const MyString& name, BaseFile* parent);
	virtual void execute(User* user) = 0;
	virtual ~ExecutableFile() = default;
	
	void serialise(std::ostream& ofs) const override;
	void deserialise(std::istream& ifs) override;
	friend class EchoCommand;
	friend class RemoveFileCommand;
};