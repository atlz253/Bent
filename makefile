# Сборка компилятора
all: flex bison
	g++ lex.yy.c bison.tab.c print.cpp -o compiler

debug: flex bison
	g++ -DDEBUG lex.yy.c bison.tab.c print.cpp -o compiler

# Генерация лексического анализатора
flex: flex.l
	flex flex.l

# Генерация синтаксического анализатора    
bison: bison.y
	bison -d bison.y
