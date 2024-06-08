#pragma once
#include "Role.h"
class Editor: public BaseRole {
public:
	BaseRole* clone() const override;
	bool authorisedCommand(const BaseCommand* command) const override;
};