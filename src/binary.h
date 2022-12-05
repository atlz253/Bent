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

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Binary();
};

#endif // BINARY_H