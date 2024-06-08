#pragma once
#include "Role.h"


class Admin : public BaseRole {
public:
	BaseRole* clone() const override;
	bool authorisedCommand(const BaseCommand*) const override;
};