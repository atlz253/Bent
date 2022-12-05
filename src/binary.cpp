#include "binary.h"

#include <iostream>

Binary::Binary(const char *op, Expression *arg1, Expression *arg2) : op(op), arg1(arg1), arg2(arg2) 
{
}

Binary::~Binary()
{
    delete arg1;
    delete arg2;
}