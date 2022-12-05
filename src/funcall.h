#ifndef FUNCALL
#define FUNCALL

#include <list>
#include <string>

#include "expression.h"

/// @brief Вызов функции
class Funcall : public Expression
{
private:
    std::string name;
    std::list<Expression *> args;

public:
    Funcall(const std::string &name, const std::list<Expression *> &args);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0);

    virtual ~Funcall();
};

#endif // FUNCALL