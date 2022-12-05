#include "unary.h"

#include <iostream>

Unary::Unary(const char *op, Expression *arg) : op(op), arg(arg)
{
}

std::string Unary::get_string(int indent)
{
    std::string str;

    str += op;

    str += arg->get_string();

    return "";
}

Unary::~Unary()
{
    delete arg;
}