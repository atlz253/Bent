#ifndef EXITOP_H
#define EXITOP_H

#include "abstract.h"

/// @brief Оператор выхода
class Exitop : public oper_t
{
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);
};

#endif // EXITOP_H