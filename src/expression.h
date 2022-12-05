#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <iostream>

/// @brief Абстрактный класс выражения
class Expression
{
protected:
    Expression() {}

public:
    virtual ~Expression() {}

    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    virtual std::string get_string(int indent = 0);

    /// @brief Печатает выражение в терминал
    /// @param indent Количество отступов
    virtual void print(int indent = 0);

    /// @brief Записать выражение в файл
    /// @param file Ссылка на файл
    /// @param indent Количество отступов
    virtual void write(FILE *file, int indent = 0);
};

#endif // ABSTRACT_H