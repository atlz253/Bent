#include "chain.h"

#include <iostream>

void Chain::Append(Expression *op)
{
    ops.push_back(op);
}

Chain::Chain() {}

Chain::Chain(Expression *op1, Expression *op2)
{
    Append(op1);
    Append(op2);
}

int Chain::Size()
{
    return ops.size();
}

Chain::~Chain()
{
    for (std::list<Expression *>::iterator iterator = ops.begin(); iterator != ops.end(); iterator++)
    {
        delete *iterator;
    }
}