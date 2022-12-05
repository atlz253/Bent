#include "unary.h"

#include <iostream>

Unary::Unary(const char *op, Expression *arg) : op(op), arg(arg)
{
}

std::string Unary::get_string(int indent)
{
    std::string str;

    str = op + arg->get_string();

    return str;
}

Unary::~Unary()
{
    delete arg;
}