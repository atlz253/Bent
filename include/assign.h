#ifndef ASSIGN_H
#define ASSIGN_H

#include <string>

#include "abstract.h"

/// @brief Операция присваивания
class Assign : public expr_t
{
private:
    std::string name;
    expr_t *value;

public:
    Assign(const std::string &name, expr_t *value);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print();

    virtual ~Assign();
};

#endif // ASSIGN_H