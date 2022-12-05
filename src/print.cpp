#ifndef DEBUG_PRINT
#define DEBUG_PRINT

#include "print.h"

#include <iostream>
#include <stdarg.h>

void debug_print(const char *format, ...)
{
#ifdef DEBUG
    va_list argPtr;
    int count;

    va_start(argPtr, format);                 // Получить список переменных параметров
    fflush(stdout);                           // Принудительно обновить выходной буфер
    count = vfprintf(stderr, format, argPtr); // Вывод информации на стандартное устройство потока ошибок
    va_end(argPtr);                           // Конец списка параметров переменной
#endif
}

void print_help()
{
    std::cout << std::endl
              << "Транслятор Bent™" << std::endl
              << std::endl
              << "Превращает великолепный Bent Code™ в Python Code" << std::endl
              << "------------------------------------------------" << std::endl
              << std::endl
              << "--help - Выводит данное сообщение" << std::endl
              << std::endl
              << "Пользоваться данным транслятором достаточно просто:" << std::endl
              << "./compiler.exe inputFile.b [outputFile.py]" << std::endl
              << '\t' << "inputFile.b - файл с Bent Code™, который вы хотите транслировать в код на Python" << std::endl
              << '\t' << "outputFile.py (по умолчанию out.py) - файл для записи полученного кода на Python" << std::endl
              << std::endl;
}

void yyerror(const char *s) // Печать сообщений об ошибке
{
    fprintf(stderr, "%s\n", s);
}

#endif // DEBUG_PRINT
