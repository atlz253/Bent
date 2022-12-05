#include "assign.h"

#include <iostream>

Assign::Assign(const std::string &name, Expression *value) : name(name), value(value)
{
}

Assign::~Assign()
{
    delete value;
}