#ifndef DEBUG_PRINT
#define DEBUG_PRINT

#include "print.h"

#include <stdio.h>
#include <stdarg.h>

void debug_print(const char *format, ...)
{
#ifdef DEBUG
    va_list argPtr;
    int count;

    va_start(argPtr, format);                  // Получить список переменных параметров
    fflush(stdout);                            // Принудительно обновить выходной буфер
    count = vfprintf(stderr, format, argPtr);  // Вывод информации на стандартное устройство потока ошибок
    va_end(argPtr);                            // Конец списка параметров переменной
#endif
}

void yyerror(char *s) // Печать сообщений об ошибке
{
    fprintf (stderr, "%s\n", s);
}

#endif // DEBUG_PRINT
