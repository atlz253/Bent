#include <iostream>
#include <windows.h>

#include "flex.h"
#include "print.h"

extern FILE* yyin;
extern FILE* yyout;

int yyparse();

/// @brief Точка входа в программу
int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);

    if (argc == 2 && !strcmp(argv[1], "--help"))
    {
        print_help();
    }
    else if (argc == 3 || argc == 2)
    {
        const char* inputFileName = argv[1];

        if ((yyin = fopen(inputFileName, "r")) == NULL)
        {
            yyerror("Не удалось открыть входной файл");

            return -1;
        }

        const char* outFileName = (argc == 2) ? "out.py" : argv[2];

        if ((yyout = fopen(outFileName, "w")) == NULL)
        {
            yyerror("Не удалось открыть выходной файл");

            return -1;
        }

        yyparse();
    }
    else
    {
        print_help();
    }

   
    return 0;
}