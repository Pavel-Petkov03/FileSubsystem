#pragma once
#include "Role.h"
class Viewer : public BaseRole {
public:
	BaseRole* clone() const override;
	bool authorisedCommand(const BaseCommand*) const override;
};