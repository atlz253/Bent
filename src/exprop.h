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

    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
    
    virtual ~Exprop();
};

#endif // EXPROP_H
