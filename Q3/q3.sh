lex lexer.l
yacc -d parser2.y
gcc -w y.tab.c
./a.out<input.c