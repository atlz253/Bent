# Сборка транслятора
all: flex bison
	g++ tmp\lex.yy.c tmp\bison.tab.c src\print.cpp -o compiler

# сборка отладочной версии транслятора (когда-нибудь я научусь пользоваться переменными в makefile!)
debug: flex bison
	g++ -DDEBUG tmp\lex.yy.c tmp\bison.tab.c src\print.cpp -o compiler

mktmp:
	if not exist "tmp" md "tmp"

# Генерация лексического анализатора
flex: mktmp src\flex.l
	flex -o"tmp\lex.yy.c" src\flex.l

# Генерация синтаксического анализатора    
bison: mktmp src\bison.y
	bison -d -o"tmp\bison.tab.c" src\bison.y
