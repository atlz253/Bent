#include "assign.h"

#include <iostream>

Assign::Assign(const std::string &name, Expression *value) : name(name), value(value)
{
}

void Assign::print(int indent)
{
    std::cout << name << " = ";
    value->print();
}

Assign::~Assign()
{
    delete value;
}