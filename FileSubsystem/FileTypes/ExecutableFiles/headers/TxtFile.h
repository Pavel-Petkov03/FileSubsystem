#pragma once
#include "ExecutableFile.h"
class TxtFile : public ExecutableFile {
public:
	void execute(User* user) override;
	TxtFile(const MyString& name, BaseFile* parent);
	TxtFile() = default;
	FileTypes getType() const override;
	ExecutableFile* clone() const;
};