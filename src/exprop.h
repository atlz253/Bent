#ifndef EXPROP_H
#define EXPROP_H

#include "expression.h"

/// @brief Выражение
class Exprop : public Expression
{
private:
    Expression *expr;

public:
    Exprop(Expression *expr);

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Exprop();
};

#endif // EXPROP_H
