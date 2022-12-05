#include "exprop.h"

#include <iostream>

Exprop::Exprop(Expression *expr) : expr(expr)
{
}

void Exprop::print(int indent)
{
    expr->print();
    std::cout << ";" << std::endl;
}

Exprop::~Exprop()
{
    delete expr;
}