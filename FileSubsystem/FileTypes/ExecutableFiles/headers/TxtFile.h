#pragma once
#include "ExecutableFile.h"
class TxtFile : public ExecutableFile {
public:
	void execute(User* user) override;
	TxtFile(const MyString& name, BaseFile* parent);
	ExecutableFile* clone() const;
};