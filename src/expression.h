#ifndef ABSTRACT_H
#define ABSTRACT_H

/// @brief Абстрактный класс выражения
class Expression
{
protected:
    Expression() {}

public:
    virtual ~Expression() {}

    /// @brief Печатает блок кода
    /// @param indent Количество отступов 
    virtual void print(int indent = 0) = 0;
};

#endif // ABSTRACT_H