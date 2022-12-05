#ifndef WHILEOP_H
#define WHILEOP_H

#include "block.h"
#include "abstract.h"

/// @brief Цикл while
class Whileop : public oper_t
{
    expr_t *cond;
    Block ops;

public:
    Whileop(expr_t *cond, oper_t *ops);

    /// @brief Печатает блок кода
    /// @param indent Количество отступов
    virtual void print(int indent = 0);

    virtual ~Whileop();
};

#endif // WHILEOP_H