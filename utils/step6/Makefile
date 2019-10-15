CFLAGS = -Wall -pedantic -std=c11 -ggdb -I. -g
CC = gcc
MAKE = make

.PHONY: all clean

all: queuetest queuetest2 queuetest3 queuetest4 queuetest5 queuetest6 queuetest7 queuetest8 queuetest9 queuetest10 queuetest11 queuetest12

queuo.o: queue.c queue.h
	gcc $(CFALGS) -c queue.c
queuetest: queuetest.o queue.o
queuetest2: queuetest2.o queue.o
queuetest3: queuetest3.o queue.o
queuetest4: queuetest4.o queue.o
queuetest5: queuetest5.o queue.o
queuetest6: queuetest6.o queue.o
queuetest7: queuetest7.o queue.o
queuetest8: queuetest8.o queue.o
queuetest9: queuetest9.o queue.o
queuetest10: queuetest10.o queue.o
queuetest11: queuetest11.o queue.o
queuetest12: queuetest12.o queue.o

%.o: %.c %.h 
	gcc $(CFLAGS) -c $< 

clean:
	rm -rf *.dSYM 
	rm -f *~ *.o
	rm -f queuetest queuetest2 queuetest3 queuetest4 queuetest5 queuetest6 queuetest7 queuetest8 queuetest9 queuetest10 queuetest11
