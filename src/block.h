#ifndef BLOCK_H
#define BLOCK_H

#include <list>

#include "expression.h"

/// @brief Блок кода
class Block : public Expression
{
    std::list<Expression *> ops;

private:
    void Append(Expression *op);

public:
    Block();
    Block(Expression *op);
    Block(Expression *op1, Expression *op2);
    
    int Size();

    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
    
    virtual ~Block();
};

#endif // BLOCK_H