#include "../headers/Role.h"

std::ostream& operator<<(std::ostream& ofs, const BaseRole& role)
{
	ofs << (int)role.getType() << std::endl;
	return ofs;
}