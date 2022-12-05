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
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
};

#endif // VALUE_H