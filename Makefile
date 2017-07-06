Stack.o: Stack.c Stack.h
	gcc -std=c99 -c Stack.c -o Stack.o
Queue.o: Queue.c Queue.h
	gcc -std=c99 -c Queue.c -o Queue.o
Advstring.o: Advstring.c Advstring.h
	gcc -std=c99 -c Advstring.c -o Advstring.o
Function.o: Function.c Function.h
	gcc -std=c99 -c Function.c -o Function.o
rpnStack.o: rpnStack.c rpnStack.h
	gcc -std=c99 -c rpnStack.c -o rpnStack.o

dStack.o: Stack.c Stack.h
	gcc -g -std=c99 -c Stack.c -o Stack.o
dQueue.o: Queue.c Queue.h
	gcc -g -std=c99 -c Queue.c -o Queue.o
dAdvstring.o: Advstring.c Advstring.h
	gcc -g -std=c99 -c Advstring.c -o Advstring.o
dFunction.o: Function.c Function.h
	gcc -g -std=c99 -c Function.c -o Function.o
drpnStack.o: rpnStack.c rpnStack.h
	gcc -g -std=c99 -c rpnStack.c -o rpnStack.o


build: rpn.c Stack.o Queue.o Advstring.o Function.o rpnStack.o
	gcc -std=c99 rpn.c Stack.o Queue.o Advstring.o Function.o rpnStack.o -o rpc

debug: rpn.c dStack.o dQueue.o dAdvstring.o dFunction.o drpnStack.o
	gcc -g -std=c99 rpn.c Stack.o Queue.o Advstring.o Function.o rpnStack.o -o rpc
