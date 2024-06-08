#pragma once
#include "../Command/BaseCommand.h"
#include <ostream>
class BaseRole {
public:
	virtual bool authorisedCommand(const BaseCommand* command) const = 0;
	virtual BaseRole* clone() const = 0;
	virtual ~BaseRole() = default;
};