#ifndef BLOCK_H
#define BLOCK_H

#include <list>

#include "abstract.h"

/// @brief Блок кода
class Block : public oper_t
{
    std::list<oper_t *> ops;

private:
    void Append(oper_t *op);

public:
    Block();
    Block(oper_t *op);
    Block(oper_t *op1, oper_t *op2);
    
    int Size();

    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
    
    virtual ~Block();
};

#endif // BLOCK_H