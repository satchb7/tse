CFLAGS=-Wall -pedantic -std=c11 -ggdb -I.-g

.PHONY: all clean

all: listtest listtest2 listtest3 listtest4 listtest5

list.o:	list.c list.h
	gcc $(CFLAGS) -c list.c

listtest.o:	listtest.c list.h
	gcc $(CFLAGS) -c listtest.c 

listtest2.o:	listtest2.c list.h
	gcc $(CFLAGS) -c listtest2.c 

listtest3.o:	listtest3.c list.h
	gcc $(CFLAGS) -c listtest3.c 

listtest4.o:	listtest4.c list.h
	gcc $(CFLAGS) -c listtest4.c 

listtest5.o: listtest5.c list.h
	gcc $(CFLAGS) -c listtest5.c

listtest:	listtest.o list.o
	gcc $(CFLAGS) listtest.o list.o -o listtest

listtest2:	listtest2.o list.o
	gcc $(CFLAGS) listtest2.o list.o -o listtest2

listtest3:	listtest3.o list.o
	gcc $(CFLAGS) listtest3.o list.o -o listtest3

listtest4:	listtest4.o list.o
	gcc $(CFLAGS) listtest4.o list.o -o listtest4

listtest5: listtest5.o list.o
	gcc $(CFLAGS) listtest5.o list.o -o listtest5

clean:
	rm -f *.o *~ listtest listtest2 listtest3 listtest4 listtest5

