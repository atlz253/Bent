#ifndef PRINT_H
#define PRINT_H

/// @brief Функция отладочной печати
/// @param format Строка аналогичная по применению printf
/// @param  Параметры
void debug_print(const char *format, ...);

/// @brief Печатает справку по программе
void print_help();

/// @brief Печать сообщение об ошибке
/// @param s Строка с причиной ошибки
void yyerror(const char *s);

#endif // PRINT_H
