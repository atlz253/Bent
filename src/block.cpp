#include "block.h"

#include <iostream>

#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define foreach(i, list)                           \
    typedef typeof(list) TOKENPASTE2(T, __LINE__); \
    for (TOKENPASTE2(T, __LINE__)::iterator i = list.begin(); i != list.end(); i++)

void Block::Append(oper_t *op)
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

Block::Block(oper_t *op)
{
    Append(op);
}

Block::Block(oper_t *op1, oper_t *op2)
{
    Append(op1);
    Append(op2);
}

int Block::Size()
{
    return ops.size();
}

void Block::print(int indent)
{
    foreach (i, ops)
    {
        std::cout << std::string(indent, '\t');
        (*i)->print(indent);
    }
}

Block::~Block()
{
    foreach (i, ops)
    {
        delete *i;
    }
}