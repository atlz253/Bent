#include "whileop.h"

#include <iostream>

Whileop::Whileop(Expression *cond, Expression *ops) : cond(cond), ops(ops) 
{
}

Whileop::~Whileop() 
{ 
    delete cond; 
}