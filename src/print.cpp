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
              << "Превращает великолепный Bent Code™ в любой другой (если очень сильно захотеть)" << std::endl
              << "------------------------------------------------------------------------------" << std::endl
              << std::endl
              << "--help (-h) - Выводит данное сообщение" << std::endl
              << std::endl
              << "--print (-p) - Напечатать результат работы в консоль" << std::endl
              << std::endl
              << "--input=\"filename\" (-i) - файл с Bent Code™, который вы хотите транслировать" << std::endl
              << std::endl
              << "--output=\"filename\" [out.py] (-i) - выходной файл для записи полученного кода" << std::endl
              << std::endl
              << "Пользоваться данным транслятором достаточно просто:" << std::endl
              << "./compiler.exe --input=\"inputFile.bent\" [--output=\"outputFile.py\"]" << std::endl
              << std::endl;
}

void yyerror(const char *s) // Печать сообщений об ошибке
{
    fprintf(stderr, "%s\n", s);
}

#endif // DEBUG_PRINT
