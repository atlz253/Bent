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

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Funcall();
};

#endif // FUNCALL