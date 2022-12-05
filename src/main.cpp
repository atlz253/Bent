#include <iostream>
#include <windows.h>

#include "flex.h"
#include "bent.h"
#include "print.h"

extern FILE *yyin;
extern FILE *yyout;

extern Expression *root;

int yyparse();

/// @brief Точка входа в программу
int main(int argc, char *argv[])
{
    bool stdPrint = false;

    SetConsoleOutputCP(CP_UTF8);

    if (argc == 1 || argc == 2 && !strcmp(argv[1], "--help"))
    {
        print_help();

        return 0;
    }

    char *str;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            print_help();

            return 0;
        }
        else if (!strcmp(argv[i], "-p") || !strcmp(argv[i], "--print"))
        {
            stdPrint = true;
        }
        else if ((str = strtok(argv[i], "=")))
        {
            if (!strcmp(str, "-i") || !strcmp(str, "--input"))
            {
                if (yyin)
                {
                    yyerror("Указано несколько входных файлов");

                    return -1;
                }

                str = strtok(NULL, "=");

                if (!(yyin = fopen(str, "r")))
                {
                    yyerror("Не удалось открыть входной файл");

                    return -1;
                }
            }
            else if (!strcmp(str, "-o") || !strcmp(str, "--output"))
            {
                if (yyout)
                {
                    yyerror("Указано несколько выходных файлов");

                    return -1;
                }

                str = strtok(NULL, "=");

                if (!(yyout = fopen(str, "w")))
                {
                    yyerror("Не удалось открыть выходной файл");

                    return -1;
                }
            }
            else
            {
                yyerror("Не удалось обработать аргумент. Используйте --help для справки.");

                return -1;
            }

            str = nullptr;
        }
        else
        {
            yyerror("Не удалось обработать аргумент. Используйте --help для справки.");

            return -1;
        }

    }

    if (!yyin)
    {
        yyerror("Не был передан входной файл. Используйте --help для справки.");

        return -1;
    }

    if (!yyout && !stdPrint) // Не был передан выходной файл
    {
        if (!(yyout = fopen("out.py", "w")))
        {
            yyerror("Не удалось открыть выходной файл");

            return -1;
        }
    }

    yyparse();
    
    if (!stdPrint)
    {
        root->write(yyout);
    }
    else
    {
        root->print();
    }

    return 0;
}