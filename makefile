all:
# Генерация лексического анализатора
	flex flex.l    

# Компиляция лексического анализатора    
	gcc .\lex.yy.c    