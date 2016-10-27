
t9: t9.o node.o
	gcc -Wall -std=c11 -g -o t9 t9.o node.o

t9.o: t9.c node.h
	gcc -Wall -std=c11 -g -c t9.c 

node.o: node.c node.h
	gcc -Wall -std=c11 -g -c node.c


clean:
	rm -f *.o t9 *~
