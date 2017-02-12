flextest: lex.yy.c
	gcc -g -o flextest lex.yy.c

lex.yy.c: flextest.l
	flex flextest.l

chars:
	gcc -E ltests/chars.c | ./flextest

kw:
	gcc -E ltests/kw.c | ./flextest

num:
	gcc -E ltests/num.c | ./flextest

op:
	gcc -E ltests/op.c | ./flextest

run:
	gcc -E ltests/*.c | ./flextest >fltest.out 2>fltest.err

