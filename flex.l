 // В данном файле описан лексический анализатор, который будет сгенерирован при помощи flex.
 // С помощью лексического анализатора мы сможем разбирать входной код на минимальные едицы языка - лексемы.

 //
 // Строки, заключенные в %{%}, скопируются напрямую в сгенерированный парсер
 //

%{
    #include "flex.h"

    #include <string>
    #include "bison.tab.h"
    #include "print.h"
%}

 //
 // Опции генератора
 //

 // Создать переменную int yylineno, в которой будет храниться номер текущей строки (удобна для отладки)
%option yylineno

%option noyywrap

%x STR

 // разделитель области объявлений и области правил языка
%%

 // Правила языка
 // В каждом правиле слева пишется регулярное выражение, справа — код на С

[/][/].*\n      ; // Если встретили комментарий, то ничего не делаем

if              return IF;
else            return ELSE;
while           return WHILE;
exit            return EXIT;
==              return EQ;
[<]=            return LE;
>=              return GE;
!=              return NE;

[0-9]+          { // Обработка найденных чисел
                    yylval.str = new std::string(yytext);
                  
                    debug_print("[Лексический анализатор] найдена числовая лексема: %s\n", yylval.str->c_str());

                    return NUM;  
                }

[a-zA-Z_][a-zA-Z0-9_]*  { 
                            yylval.str = new std::string(yytext);
                            
                            debug_print("[Лексический анализатор] найден новый ID: %s\n", yylval.str->c_str());

                            return ID;
                        }

["]                     {
                            yylval.str = new std::string(); 
                            
                            debug_print("[Лексический анализатор] обнаружена строка\n");

                            BEGIN(STR); 
                        }

<STR>[^\\\n"]+  {
                            int i = 0;

                            while (yytext[i] != 0)
                            {
                                yylval.str->push_back(yytext[i++]);
                            }

                            debug_print("[Лексический анализатор] добавлена последовательность символов к строке: %s\n", yylval.str->c_str());
                }

<STR>\\n        {
                            yylval.str->push_back('\n');

                            debug_print("[Лексический анализатор] добавлен символ переноса текста в строку\n");
                }

<STR>\\["]      {
                    debug_print("[Лексический анализатор] обнаружены \" в строке\n");

                    yylval.str->push_back('"');
                }

<STR>\\         yyerror("Invalid escape sequence");

<STR>\n         yyerror("Newline in string literal");

<STR>["]        { 
                    debug_print("[Лексический анализатор] конец строки: %s\n", yylval.str->c_str());

                    BEGIN(INITIAL); 
                    
                    return STRING; 
                }

[ \t\r\n]       ; // Игнорируем проблемы и переходы на новую строку

[-{};()=<>+*/!,] { return *yytext; }

.               { 
                    yyerror("Invalid character");
                    // debug_print("[Лексический анализатор] найдена символьная лексема: %c\n", *yytext);

                    // return *yytext; 
                }

%%
