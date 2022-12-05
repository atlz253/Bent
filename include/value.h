#ifndef VALUE_H
#define VALUE_H

#include <string>

#include "abstract.h"

class Value : public expr_t
{
private:
    std::string text;

public:
    Value(const std::string &text);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print();
};

#endif // VALUE_H