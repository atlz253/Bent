#ifndef UNARY_H
#define UNARY_H

#include "abstract.h"

/// @brief Унарная операция
class Unary : public expr_t
{
private:
    const char *op;
    expr_t *arg;

public:
    Unary(const char *op, expr_t *arg);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print();

    virtual ~Unary();
};

#endif // UNARY_H