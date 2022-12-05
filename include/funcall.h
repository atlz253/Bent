#ifndef FUNCALL
#define FUNCALL

#include <list>
#include <string>

#include "abstract.h"

/// @brief Вызов функции
class Funcall : public expr_t
{
private:
    std::string name;
    std::list<expr_t *> args;

public:
    Funcall(const std::string &name, const std::list<expr_t *> &args);
    
    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print();

    virtual ~Funcall();
};

#endif // FUNCALL