#ifndef CHAIN_H
#define CHAIN_H

#include <list>

#include "expression.h"

/// @brief Цепочка вызовов
class Chain : public Expression
{
    std::list<Expression *> ops;

private:
    void Append(Expression *op);

public:
    Chain();
    Chain(Expression *op1, Expression *op2);

    int Size();

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Chain();
};

#endif // CHAIN_H