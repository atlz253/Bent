#ifndef IMPORT_H
#define IMPORT_H

#include <string>

#include "expression.h"

/// @brief Импорт модуля
class Import : public Expression
{
private:
    Expression *id;

public:
    Import(Expression *id);
    
    /// @brief Возвращает строку с выражением
    /// @param indent Количество отступов
    /// @return Строка кода
    std::string get_string(int indent = 0) override;

    virtual ~Import();
};

#endif // IMPORT_H