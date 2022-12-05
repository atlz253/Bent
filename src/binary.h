#ifndef BINARY_H
#define BINARY_H

#include "expression.h"

class Binary : public Expression
{
private:
    const char *op;
    Expression *arg1, *arg2;

public:
    Binary(const char *op, Expression *arg1, Expression *arg2);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
    
    virtual ~Binary();
};

#endif // BINARY_H