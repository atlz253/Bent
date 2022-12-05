#include "unary.h"

#include <iostream>

Unary::Unary(const char *op, Expression *arg) : op(op), arg(arg)
{
}

Unary::~Unary()
{
    delete arg;
}