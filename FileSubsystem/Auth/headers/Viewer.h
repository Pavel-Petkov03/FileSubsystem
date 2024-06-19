#pragma once
#include "Role.h"
class Viewer : public BaseRole {
public:
	BaseRole* clone() const override;
	RoleTypes getType() const override;
};