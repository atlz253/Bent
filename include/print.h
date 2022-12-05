// #define DEBUG

/// @brief Функция отладочной печати
/// @param format Строка аналогичная по применению printf
/// @param  Параметры
void debug_print(const char *format, ...);

/// @brief Печать сообщение об ошибке
/// @param s Строка с причиной ошибки
void yyerror(char *s);