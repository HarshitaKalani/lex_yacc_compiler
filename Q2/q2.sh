lex lexer.l
yacc -d parser1.y
gcc -w y.tab.c
./a.out<input.c