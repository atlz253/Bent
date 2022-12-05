#ifndef UNARY_H
#define UNARY_H

#include "expression.h"

/// @brief Унарная операция
class Unary : public Expression
{
private:
    const char *op;
    Expression *arg;

public:
    Unary(const char *op, Expression *arg);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);

    virtual ~Unary();
};

#endif // UNARY_H