SRC = tmp\lex.yy.c \
	  tmp\bison.tab.c \
	  src\print.cpp \
	  src\block.cpp \
	  src\exprop.cpp \
	  src\ifop.cpp \
	  src\whileop.cpp \
	  src\binary.cpp \
	  src\assign.cpp \
	  src\funcall.cpp \
	  src\unary.cpp \
	  src\value.cpp \
	  src\replace.cpp \
	  src\main.cpp \
	  src\expression.cpp

# Сборка транслятора bent -> bent
all: flex bison
	g++ $(SRC) src\string_bent.cpp -Iinclude -Isrc -o bent

# сборка отладочной версии транслятора bent -> bent (когда-нибудь я научусь пользоваться переменными в makefile!)
debug: flex bison
	g++ -DDEBUG $(SRC) src\string_bent.cpp -Iinclude -Isrc -o bent

# Сборка транслятора bent -> python
python: flex bison
	g++ $(SRC) src\string_python.cpp -Iinclude -Isrc -o bent

# сборка отладочной версии транслятора bent -> python
pdebug: flex bison
	g++ -DDEBUG $(SRC) src\string_python.cpp -Iinclude -Isrc -o bent

mktmp:
	if not exist "tmp" md "tmp"

# Генерация лексического анализатора
flex: mktmp src\flex.l
	flex -o"tmp\lex.yy.c" src\flex.l

# Генерация синтаксического анализатора    
bison: mktmp src\bison.y
	bison -d -o"tmp\bison.tab.c" src\bison.y
