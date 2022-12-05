 // В данном файле описан синтаксический анализатор, который будет сгенерирован при помощи bison.
 // С помощью синтаксический анализатора мы сможем проверить грамматику нашего языка.

 //
 // Строки, заключенные в %{%}, скопируются напрямую в сгенерированный парсер
 //

%{
    #include <list>
    #include <iostream>
    
    #include "print.h"

    #include "ifop.h"
    #include "block.h"
    #include "unary.h"
    #include "value.h"
    #include "exprop.h"
    #include "exitop.h"
    #include "binary.h"
    #include "assign.h"
    #include "whileop.h"
    #include "funcall.h"
    #include "replace.h"

    extern int yylineno;
    
    extern int yylex();  
%}

%code requires
{
    #include <list>
    #include <string>

    #include "abstract.h"    
}

%union
{
    std::string* str;
    oper_t* oper;
    expr_t* expr;
    std::list<expr_t *>* args;
}

%token IF ELSE WHILE EXIT
%token EQ LE GE NE

 // Объявление токена - десятичного числа
%token STRING NUM ID

%type<str> ID NUM STRING
%type<oper> OPS OP1 OP2 OP
%type<expr> EXPR EXPR1 EXPR2 TERM VAL ARG
%type<args> ARGS

 // Разделитель области объявлений и области правил грамматики
%%

PROGRAM:    OPS {
                    debug_print("[Синтаксический анализатор] печать результата\n");
                    $1->print(); 
                    delete $1;
                    return 0; 
                 }
;

OPS:    OP
|       OPS OP { 
                    debug_print("[Синтаксический анализатор] новый блок кода\n");
                    $$ = new Block($1, $2); 
                }
;

OP: OP1 | OP2
;

OP1: '{' OPS '}' { $$ = $2; } 
|       EXPR ';'                        {
                                            debug_print("[Синтаксический анализатор] Обнаружен конец команды\n");

                                            $$ = new Exprop($1); 
                                        }
|       IF '(' EXPR ')' OP1 ELSE OP1    { 
                                            debug_print("[Синтаксический анализатор] Обнаружено ветвление\n");

                                            $$ = new Ifop($3, $5, $7); 
                                        }
|       WHILE '(' EXPR ')' OP1          {
                                            debug_print("[Синтаксический анализатор] Обнаружен цикл\n");

                                            $$ = new Whileop($3, $5); 
                                        }
|       EXIT ';'                        {
                                            debug_print("[Синтаксический анализатор] Обнаружен оператор выхода\n");

                                            $$ = new Exitop(); 
                                        }
;

OP2: IF '(' EXPR ')' OP              { $$ = new Ifop($3, $5, new Block()); }
|       IF '(' EXPR ')' OP1 ELSE OP2    { $$ = new Ifop($3, $5, $7); }
|       WHILE '(' EXPR ')' OP2          { $$ = new Whileop($3, $5); }
;

EXPR: EXPR1
|       ID '=' EXPR                     {
                                            debug_print("[Синтаксический анализатор] Обнаружено присваивание в переменную %s\n", $1->c_str());

                                            $$ = new Assign(*$1, $3); 
                                        }
;

EXPR1: EXPR2
|       EXPR1 EQ EXPR2                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (равно)\n");

                                            $$ = new Binary("==", $1, $3); 
                                        }
|       EXPR1 LE EXPR2                  { 
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (меньше либо равно)\n");

                                            $$ = new Binary("<=", $1, $3); 
                                        }
|       EXPR1 GE EXPR2                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (больше либо равно)\n");

                                            $$ = new Binary(">=", $1, $3); 
                                        }
|       EXPR1 NE EXPR2                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (не равно)\n");

                                            $$ = new Binary("!=", $1, $3); 
                                        }
|       EXPR1 '>' EXPR2                 {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (больше)\n");

                                            $$ = new Binary(">", $1, $3); 
                                        }
|       EXPR1 '<' EXPR2                 {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (меньше)\n");

                                            $$ = new Binary("<", $1, $3); 
                                        }
;

EXPR2: TERM
|       EXPR2 '+' TERM                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сложения\n");

                                            $$ = new Binary("+", $1, $3); 
                                        }
|       EXPR2 '-' TERM                  { 
                                            debug_print("[Синтаксический анализатор] Обнаружена операция вычитания\n");

                                            $$ = new Binary("-", $1, $3); 
                                        }
;

TERM: VAL
|       TERM '*' VAL                    {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция умножения\n");

                                            $$ = new Binary("*", $1, $3); 
                                        }
|       TERM '/' VAL                    { 
                                            debug_print("[Синтаксический анализатор] Обнаружена операция деления\n");

                                            $$ = new Binary("/", $1, $3); 
                                        }
;

VAL: NUM { $$ = new Value(*$1); }
|       '-' VAL                         { $$ = new Unary("-", $2); }
|       '!' VAL                         { $$ = new Unary("!", $2); }
|       '(' EXPR ')'                    { $$ = $2; }
|       ID                              { $$ = new Value(*$1); }
|       ID '(' ARGS ')'                 { $$=new Funcall(*$1, *$3); }
;
;

ARGS:                                   { 
                                            debug_print("[Синтаксический анализатор] Создание пустых аргументов\n");

                                            $$ = new std::list<expr_t *>();

                                            $$->clear(); 
                                        }
|       ARG                             {
                                            debug_print("[Синтаксический анализатор] Создание аргументов\n");

                                            $$ = new std::list<expr_t *>();

                                            $$->clear(); 

                                            $$->push_back($1); 
                                        }
|       ARGS ',' ARG                    {
                                            debug_print("[Синтаксический анализатор] Обнаружен новый аргумент\n");

                                            $$ = $1; 
                                            
                                            $$->push_back($3); 
                                        }
;

ARG:    EXPR
|       STRING                          { 
                                            std::string s = '"'+replaceAll(*$1, "\n", "\\n")+'"';

                                            $$=new Value(s);

                                            debug_print("[Синтаксический анализатор] Обнаружена строка %s\n", $1->c_str()); 
                                        }
;

%%
