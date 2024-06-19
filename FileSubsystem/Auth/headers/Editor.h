#pragma once
#include "Role.h"
class Editor : public BaseRole {
public:
	BaseRole* clone() const override;
	RoleTypes getType() const override;
};