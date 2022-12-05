#include "unary.h"

#include <iostream>

Unary::Unary(const char *op, expr_t *arg) : op(op), arg(arg)
{
}

void Unary::print()
{
    std::cout << op;
    arg->print();
}

Unary::~Unary()
{
    delete arg;
}