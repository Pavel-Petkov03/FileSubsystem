#pragma once
#include "../BaseFile.hpp"

class ExecutableFile : public BaseFile {
public:
	virtual void execute() const = 0;
	virtual ~ExecutableFile() = default;
};

