CC=clang
CFLAGS=-g


lab4: lab4.o
	clang -g -o lab4 lab4.c

dist:
	clang -O3 -o lab4 lab4.c
	strip lab4

clean:
	rm -fr lab4 lab4.o *.dSYM *~
