 // В данном файле описан синтаксический анализатор, который будет сгенерирован при помощи bison.
 // С помощью синтаксический анализатора мы сможем проверить грамматику нашего языка.

 //
 // Строки, заключенные в %{%}, скопируются напрямую в сгенерированный парсер
 //

%{
    #include <list>
    #include <iostream>
    #include <windows.h>
    
    #include "print.h"
    #include "abstract.h"   
    
    #define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define foreach(i, list) typedef typeof(list) TOKENPASTE2(T,__LINE__); \
                    for(TOKENPASTE2(T,__LINE__)::iterator i = list.begin(); i != list.end(); i++)

    extern int yylineno;
    extern int yylex();

    class block : public oper_t {
        std::list<oper_t*> ops;
        void append(oper_t* op) {
            block* b = dynamic_cast<block*>(op);
            if(b) {
                ops.splice(ops.end(), b->ops, b->ops.begin(), b->ops.end());
                delete b;
            }
            else ops.push_back(op);
        }
        public:
            block() {}
            block(oper_t* op) { append(op); }
            block(oper_t* op1, oper_t* op2) { append(op1); append(op2); }
        int size() { return ops.size(); }
        virtual void print(int indent=0) {
            foreach(i, ops) {
                std::cout << std::string(indent, '\t');
                (*i)->print(indent);
            }
        }
        virtual ~block() { foreach(i, ops) delete *i; }
    };

    class exprop : public oper_t {
        expr_t* expr;
        public: exprop(expr_t* expr) : expr(expr) {}
        virtual void print(int indent=0) {
            expr->print();
            std::cout << ";" << std::endl;
        }
        virtual ~exprop() { delete expr; }
    };

    class ifop : public oper_t {
        expr_t* cond;
        block thenops, elseops;
        public: ifop(expr_t* cond, oper_t* thenops, oper_t* elseops) :
                cond(cond), thenops(thenops), elseops(elseops) {}
        virtual void print(int indent=0) {
            std::cout << "if "; cond->print();  std::cout << " {" << std::endl;
            thenops.print(indent+1);
            if (elseops.size()) {
                std::cout << std::string(indent, '\t') << "} else {" << std::endl;
                elseops.print(indent+1);
            }
            std::cout << std::string(indent, '\t') << "}" << std::endl;
        }
        virtual ~ifop() { delete cond; }
    };

    class whileop : public oper_t {
        expr_t* cond;
        block ops;
        public: whileop(expr_t* cond, oper_t* ops) : cond(cond), ops(ops) {}
        virtual void print(int indent=0) {
            std::cout << "while "; cond->print();  std::cout << " {" << std::endl;
            ops.print(indent+1);
            std::cout << std::string(indent, '\t') << "}" << std::endl;
        }
        virtual ~whileop() { delete cond; }
    };

    class exitop : public oper_t {
        virtual void print(int indent=0) { std::cout << "exit;" << std::endl; }
    };

    class binary : public expr_t {
        const char* op;
        expr_t *arg1, *arg2;
        public: binary(const char* op, expr_t *arg1, expr_t *arg2) :
                op(op), arg1(arg1), arg2(arg2) {}
        virtual void print() {
            std::cout<<"(";
            arg1->print();
            std::cout<<op;
            arg2->print();
            std::cout<<")";
        }
        virtual ~binary() { delete arg1; delete arg2; }
    };

    class assign : public expr_t {
        std::string name;
        expr_t* value;
        public: assign(const std::string& name, expr_t* value) :
                name(name), value(value) {}
        virtual void print() { std::cout<<name<<" = "; value->print(); }
        virtual ~assign() { delete value; }
    };

    class unary : public expr_t {
        const char* op;
        expr_t* arg;
        public: unary(const char* op, expr_t* arg) : op(op), arg(arg) {}
        virtual void print() { std::cout<<op; arg->print(); }
        virtual ~unary() { delete arg; }
    };

    class funcall : public expr_t {
        std::string name;
        std::list<expr_t*> args;
        public: funcall(const std::string& name,
                const std::list<expr_t*>& args) :
                name(name), args(args) {}
        virtual void print() {
            std::cout<<name<<"(";
            foreach(i,args) {
                if (i!=args.begin())
                    std::cout<<", ";
                (*i)->print();
            }
            std::cout<<")";
        }
        virtual ~funcall() { foreach(i,args) delete *i; }
    };

    class value : public expr_t {
        std::string text;
        public: value(const std::string& text) : text(text) {}
        virtual void print() { std::cout<<text; }
    };



// глобальная замена
std::string replaceAll(const std::string &where, const std::string &what, const std::string &withWhat)
{
    std::string result = where;
    while (1)
    {
        int pos = result.find(what);
        if (pos == -1)
            return result;
        result.replace(pos, what.size(), withWhat);
    }
}
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
%token STRING NUM ID END

%type<str> ID NUM STRING
%type<oper> OPS OP1 OP2 OP
%type<expr> EXPR EXPR1 EXPR2 TERM VAL ARG
%type<args> ARGS

 // Разделитель области объявлений и области правил грамматики
%%

PROGRAM:    OPS END  {
                    debug_print("[Синтаксический анализатор] печать результата\n");
                    $1->print(); 
                    delete $1;
                    return 0; 
                 }
|           END {return 0;}
;

OPS:    OP
|       OPS OP { 
                    debug_print("[Синтаксический анализатор] новый блок кода\n");
                    $$ = new block($1, $2); 
                }
;

OP: OP1 | OP2
;

OP1: '{' OPS '}' { $$ = $2; } 
|       EXPR ';'                        {
                                            debug_print("[Синтаксический анализатор] Обнаружен конец команды\n");

                                            $$ = new exprop($1); 
                                        }
|       IF '(' EXPR ')' OP1 ELSE OP1    { 
                                            debug_print("[Синтаксический анализатор] Обнаружено ветвление\n");

                                            $$ = new ifop($3, $5, $7); 
                                        }
|       WHILE '(' EXPR ')' OP1          {
                                            debug_print("[Синтаксический анализатор] Обнаружен цикл\n");

                                            $$ = new whileop($3, $5); 
                                        }
|       EXIT ';'                        {
                                            debug_print("[Синтаксический анализатор] Обнаружен оператор выхода\n");

                                            $$ = new exitop(); 
                                        }
;

OP2: IF '(' EXPR ')' OP              { $$ = new ifop($3, $5, new block()); }
|       IF '(' EXPR ')' OP1 ELSE OP2    { $$ = new ifop($3, $5, $7); }
|       WHILE '(' EXPR ')' OP2          { $$ = new whileop($3, $5); }
;

EXPR: EXPR1
|       ID '=' EXPR                     {
                                            debug_print("[Синтаксический анализатор] Обнаружено присваивание в переменную %s\n", $1->c_str());

                                            $$ = new assign(*$1, $3); 
                                        }
;

EXPR1: EXPR2
|       EXPR1 EQ EXPR2                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (равно)\n");

                                            $$ = new binary("==", $1, $3); 
                                        }
|       EXPR1 LE EXPR2                  { 
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (меньше либо равно)\n");

                                            $$ = new binary("<=", $1, $3); 
                                        }
|       EXPR1 GE EXPR2                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (больше либо равно)\n");

                                            $$ = new binary(">=", $1, $3); 
                                        }
|       EXPR1 NE EXPR2                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (не равно)\n");

                                            $$ = new binary("!=", $1, $3); 
                                        }
|       EXPR1 '>' EXPR2                 {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (больше)\n");

                                            $$ = new binary(">", $1, $3); 
                                        }
|       EXPR1 '<' EXPR2                 {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сравнения (меньше)\n");

                                            $$ = new binary("<", $1, $3); 
                                        }
;

EXPR2: TERM
|       EXPR2 '+' TERM                  {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция сложения\n");

                                            $$ = new binary("+", $1, $3); 
                                        }
|       EXPR2 '-' TERM                  { 
                                            debug_print("[Синтаксический анализатор] Обнаружена операция вычитания\n");

                                            $$ = new binary("-", $1, $3); 
                                        }
;

TERM: VAL
|       TERM '*' VAL                    {
                                            debug_print("[Синтаксический анализатор] Обнаружена операция умножения\n");

                                            $$ = new binary("*", $1, $3); 
                                        }
|       TERM '/' VAL                    { 
                                            debug_print("[Синтаксический анализатор] Обнаружена операция деления\n");

                                            $$ = new binary("/", $1, $3); 
                                        }
;

VAL: NUM { $$ = new value(*$1); }
|       '-' VAL                         { $$ = new unary("-", $2); }
|       '!' VAL                         { $$ = new unary("!", $2); }
|       '(' EXPR ')'                    { $$ = $2; }
|       ID                              { $$ = new value(*$1); }
|       ID '(' ARGS ')'                 { $$=new funcall(*$1, *$3); }
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

                                            $$=new value(s);

                                            debug_print("[Синтаксический анализатор] Обнаружена строка %s\n", $1->c_str()); 
                                        }
;

%%

 // Точка входа в сгенерированный анализатор
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    yyparse();
   
    return 0;
}