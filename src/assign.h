#ifndef ASSIGN_H
#define ASSIGN_H

#include <string>

#include "expression.h"

/// @brief Операция присваивания
class Assign : public Expression
{
private:
    std::string name;
    Expression *value;

public:
    Assign(const std::string &name, Expression *value);
    
    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Assign();
};

#endif // ASSIGN_H