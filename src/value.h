#ifndef VALUE_H
#define VALUE_H

#include <string>

#include "expression.h"

class Value : public Expression
{
private:
    std::string text;

public:
    Value(const std::string &text);
    
    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;
};

#endif // VALUE_H