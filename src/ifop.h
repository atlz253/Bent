#ifndef IFOP_H
#define IFOP_H

#include "block.h"
#include "expression.h"

class Ifop : public Expression
{
private:
    Expression *cond;
    Block thenops, elseops;

public:
    Ifop(Expression *cond, Expression *thenops, Expression *elseops);

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Ifop();
};

#endif // IFOP_H