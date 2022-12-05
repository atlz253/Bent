#include "binary.h"

#include <iostream>

Binary::Binary(const char *op, expr_t *arg1, expr_t *arg2) : op(op), arg1(arg1), arg2(arg2) 
{
}

void Binary::print()
{
    std::cout << "(";
    arg1->print();
    std::cout << op;
    arg2->print();
    std::cout << ")";
}

Binary::~Binary()
{
    delete arg1;
    delete arg2;
}