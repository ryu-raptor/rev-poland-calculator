Stack.o: Stack.c Stack.h
	gcc -std=c99 -c Stack.c -o Stack.o
Queue.o: Queue.c Queue.h
	gcc -std=c99 -c Queue.c -o Queue.o
Advstring.o: Advstring.c Advstring.h
	gcc -std=c99 -c Advstring.c -o Advstring.o
Function.o: Function.c Function.h
	gcc -std=c99 -c Function.c -o Function.o

build: rpn.c Stack.o Queue.o Advstring.o Function.o
	gcc -std=c99 rpn.c Stack.o Queue.o Advstring.o Function.o -o rpc

debug: rpn.c Stack.o Queue.o Advstring.o Function.o
	gcc -g -std=c99 rpn.c Stack.o Queue.o Advstring.o Function.o -o rpc
