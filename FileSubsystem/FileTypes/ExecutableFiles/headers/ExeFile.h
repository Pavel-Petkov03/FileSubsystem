#pragma once
#include "ExecutableFile.h"
#include "../../Utility/Vector.hpp"
#include "../../Utility/MyString.h"
#include "../../Auth/headers/User.h"

class ExeFile : public ExecutableFile {
private:

public:
	void execute(User* user) override;
	ExecutableFile* clone() const;
	ExeFile(const MyString& name, BaseFile* parent);
};