# Сборка компилятора
all: flex bison
	gcc lex.yy.c bison.tab.c print.c -o compiler

# Генерация лексического анализатора
flex: flex.l
	flex flex.l

# Генерация синтаксического анализатора    
bison: bison.y
	bison -d .\bison.y
