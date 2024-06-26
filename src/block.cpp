#include "block.h"

#include <iostream>

void Block::Append(Expression *op)
{
    Block *b = dynamic_cast<Block *>(op);
    if (b)
    {
        ops.splice(ops.end(), b->ops, b->ops.begin(), b->ops.end());
        delete b;
    }
    else
        ops.push_back(op);
}

Block::Block() {}

Block::Block(Expression *op)
{
    Append(op);
}

Block::Block(Expression *op1, Expression *op2)
{
    Append(op1);
    Append(op2);
}

int Block::Size()
{
    return ops.size();
}

Block::~Block()
{
    for (std::list<Expression *>::iterator iterator = ops.begin(); iterator != ops.end(); iterator++)
    {
        delete *iterator;
    }
}