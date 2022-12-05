#ifndef EXITOP_H
#define EXITOP_H

#include "expression.h"

/// @brief Оператор выхода
class Exitop : public Expression
{
    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;
};

#endif // EXITOP_H