#ifndef EXPROP_H
#define EXPROP_H

#include "abstract.h"

/// @brief Выражение
class Exprop : public oper_t
{
private:
    expr_t *expr;

public:
    Exprop(expr_t *expr);

    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
    
    virtual ~Exprop();
};

#endif // EXPROP_H
