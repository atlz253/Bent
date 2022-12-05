#include "binary.h"

#include <iostream>

Binary::Binary(const char *op, Expression *arg1, Expression *arg2) : op(op), arg1(arg1), arg2(arg2) 
{
}

std::string Binary::get_string(int indent)
{
    std::string str;

    str += "(" + arg1->get_string() + " " + op + " " + arg2->get_string() + ")";

    return str;
}

Binary::~Binary()
{
    delete arg1;
    delete arg2;
}