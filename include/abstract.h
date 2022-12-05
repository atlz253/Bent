#ifndef ABSTRACT_H
#define ABSTRACT_H

/// @brief Абстрактный класс оператора
class oper_t
{
protected:
    oper_t() {}

public:
    virtual ~oper_t() {}
    virtual void print(int indent = 0) = 0;
};

/// @brief Абстрактный класс выражения
class expr_t
{
protected:
    expr_t() {}

public:
    virtual ~expr_t() {}
    virtual void print() = 0;
};

#endif // ABSTRACT_H