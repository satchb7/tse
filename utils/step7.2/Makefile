CFLAGS = -Wall -pedantic -std=c11 -ggdb -I. -I../step6 -g
CC = gcc
MAKE = make

.PHONY: all clean

all: hashtest hashtest1 hashtest2 hashtest3 hashtest4 hashtest5 hashtest6

hash.o: hash.c hash.h 
	gcc $(CFLAGS) -c hash.c ../step6/queue.c

hashtest: hashtest.o hash.o ../step6/queue.o 
hashtest1: hashtest1.o hash.o ../step6/queue.o
hashtest2: hashtest2.o hash.o ../step6/queue.o
hashtest3: hashtest3.o hash.o ../step6/queue.o
hashtest4: hashtest4.o hash.o ../step6/queue.o
hashtest5: hashtest5.o hash.o ../step6/queue.o
hashtest6: hashtest6.o hash.o ../step6/queue.o

%.o: %.c %.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.dSYM 
	rm -f *~ *.o
	rm -f hashtest hashtest1 hashtest2 hashtest3 hashtest4 hashtest5 hashtest6
