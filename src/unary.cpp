#include "unary.h"

#include <iostream>

Unary::Unary(const char *op, Expression *arg) : op(op), arg(arg)
{
}

void Unary::print(int indent)
{
    std::cout << op;
    arg->print();
}

Unary::~Unary()
{
    delete arg;
}