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

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Whileop();
};

#endif // WHILEOP_H