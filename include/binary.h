#ifndef BINARY_H
#define BINARY_H

#include "abstract.h"

class Binary : public expr_t
{
private:
    const char *op;
    expr_t *arg1, *arg2;

public:
    Binary(const char *op, expr_t *arg1, expr_t *arg2);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print();
    
    virtual ~Binary();
};

#endif // BINARY_H