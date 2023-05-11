#include "Member.h"

std::string Member::getName()
{
    return _name;
}

int Member::getId()
{
    return _id;
}

void Member::setId(int id)
{
    _id = id;
}
