#include "exprop.h"

#include <iostream>

Exprop::Exprop(Expression *expr) : expr(expr)
{
}

std::string Exprop::get_string(int indent)
{
    std::string str;

    str = expr->get_string() + ";\n";

    return str;
}

Exprop::~Exprop()
{
    delete expr;
}