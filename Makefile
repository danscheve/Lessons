all: cycleAgain doubly_ll singly_ll insertion_sort perms prime queue reverse stack
CC=gcc

CFLAGS=-I.
DEPS=fifo.h

%.o: %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)
cycleAgain: cycleAgain.o
	gcc -o cycleAgain cycleAgain.c -I.
doubly_ll: doubly_ll.o
	gcc -o doubly_ll doubly_ll.c -I.
singly_ll: singly_ll.o
	gcc -o singly_ll singly_ll.c -I.
insertion_sort: insertion_sort.o
	gcc -o insertion_sort insertion_sort.c -I.
perms: perms.o
	gcc -o perms perms.c -I.
prime: prime.o
	gcc -o prime prime.c -I.
queue: queue.o
	gcc -o queue queue.c -I.
reverse: reverse.o
	gcc -o reverse reverse.c -I.
stack: stack.o
	gcc -o stack stack.c -I.
