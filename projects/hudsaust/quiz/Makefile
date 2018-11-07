CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: quizResults.out

quizResults.out: testme.c
	gcc -o testme -g testme.c $(CFLAGS)
	./testme
	gcov -stdout testme.c

