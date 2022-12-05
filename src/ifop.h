#ifndef IFOP_H
#define IFOP_H

#include "block.h"
#include "expression.h"

class Ifop : public Expression
{
private:
    Expression *cond;
    Block thenops, elseops;

public:
    Ifop(Expression *cond, Expression *thenops, Expression *elseops);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов
    virtual void print(int indent = 0);
    
    virtual ~Ifop();
};

#endif // IFOP_H