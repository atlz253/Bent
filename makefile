SRC = tmp\lex.yy.c \
	  tmp\bison.tab.c \
	  src\print.cpp \
	  src\block.cpp \
	  src\exprop.cpp \
	  src\ifop.cpp \
	  src\whileop.cpp \
	  src\exitop.cpp \
	  src\binary.cpp \
	  src\assign.cpp \
	  src\funcall.cpp \
	  src\unary.cpp \
	  src\value.cpp \
	  src\replace.cpp \
	  src\main.cpp \
	  src\expression.cpp

# Сборка транслятора
all: flex bison
	g++ $(SRC) -Iinclude -Isrc -o compiler

# сборка отладочной версии транслятора (когда-нибудь я научусь пользоваться переменными в makefile!)
debug: flex bison
	g++ -DDEBUG $(SRC) -Iinclude -Isrc -o compiler

mktmp:
	if not exist "tmp" md "tmp"

# Генерация лексического анализатора
flex: mktmp src\flex.l
	flex -o"tmp\lex.yy.c" src\flex.l

# Генерация синтаксического анализатора    
bison: mktmp src\bison.y
	bison -d -o"tmp\bison.tab.c" src\bison.y
