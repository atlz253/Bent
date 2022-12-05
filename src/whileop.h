#ifndef WHILEOP_H
#define WHILEOP_H

#include "block.h"
#include "expression.h"

/// @brief Цикл while
class Whileop : public Expression
{
    Expression *cond;
    Block ops;

public:
    Whileop(Expression *cond, Expression *ops);

    /// @brief Печатает блок кода
    /// @param indent Количество отступов
    virtual void print(int indent = 0);

    virtual ~Whileop();
};

#endif // WHILEOP_H