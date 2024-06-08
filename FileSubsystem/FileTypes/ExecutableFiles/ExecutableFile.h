#pragma once
#include "../BaseFile.h"

class ExecutableFile : public BaseFile {
public:
	virtual void execute() const = 0;
	virtual ~ExecutableFile() = default;
};

