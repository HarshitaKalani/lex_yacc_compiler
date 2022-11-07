lex lexer.l
yacc -d parser3.y
gcc -w y.tab.c
./a.out<input.c