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

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Unary();
};

#endif // UNARY_H