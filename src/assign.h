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
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);

    virtual ~Assign();
};

#endif // ASSIGN_H