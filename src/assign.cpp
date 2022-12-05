#include "assign.h"

#include <iostream>

Assign::Assign(const std::string &name, Expression *value) : name(name), value(value)
{
}

std::string Assign::get_string(int indent)
{
    std::string str;

    str = name + " = " + value->get_string();

    return str;
}

Assign::~Assign()
{
    delete value;
}