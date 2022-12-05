#include "exprop.h"

#include <iostream>

Exprop::Exprop(Expression *expr) : expr(expr)
{
}

Exprop::~Exprop()
{
    delete expr;
}