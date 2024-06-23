#pragma once
#include "Role.h"
class Admin : public BaseRole {
public:
	BaseRole* clone() const override;
	RoleTypes getType() const override;
};