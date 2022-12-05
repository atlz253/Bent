#include "ifop.h"

#include <iostream>

Ifop::Ifop(Expression *cond, Expression *thenops, Expression *elseops) : cond(cond), thenops(thenops), elseops(elseops)
{
}

Ifop::~Ifop()
{
    delete cond;
}