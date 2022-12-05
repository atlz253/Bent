#include "assign.h"

#include <iostream>

Assign::Assign(const std::string &name, expr_t *value) : name(name), value(value)
{
}

void Assign::print()
{
    std::cout << name << " = ";
    value->print();
}

Assign::~Assign()
{
    delete value;
}