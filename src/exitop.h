#ifndef EXITOP_H
#define EXITOP_H

#include "expression.h"

/// @brief Оператор выхода
class Exitop : public Expression
{
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
};

#endif // EXITOP_H