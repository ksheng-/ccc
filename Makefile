all: parser

parser.tab.c parser.tab.h: parser.y
	bison -d -v -t --report=all parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser: lex.yy.c parser.tab.c parser.tab.h ast.c sym.c ptypes.h ast.h sym.h
	gcc -g -o parser parser.tab.c lex.yy.c ast.c sym.c

clean:
	rm parser parser.tab.c lex.yy.c parser.tab.h

