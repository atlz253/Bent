#ifndef IFOP_H
#define IFOP_H

#include "block.h"
#include "abstract.h"

class Ifop : public oper_t
{
private:
    expr_t *cond;
    Block thenops, elseops;

public:
    Ifop(expr_t *cond, oper_t *thenops, oper_t *elseops);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов
    virtual void print(int indent = 0);
    
    virtual ~Ifop();
};

#endif // IFOP_H