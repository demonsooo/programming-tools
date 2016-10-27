bench: bench.o getmem.o freemem.o check_heap.o print_heap.o get_mem_stats.o
	gcc -Wall -std=c11 -g -o bench bench.o getmem.o freemem.o check_heap.o print_heap.o get_mem_stats.o

bench.o: bench.c mem.h
	gcc -Wall -std=c11 -g -c bench.c

getmem.o: getmem.c mem_impl.h
	gcc -Wall -std=c11 -g -c getmem.c

freemem.o: freemem.c mem_impl.h
	gcc -Wall -std=c11 -g -c freemem.c

check_heap.o: check_heap.c mem_impl.h
	gcc -Wall -std=c11 -g -c check_heap.c

print_heap.o: print_heap.c mem_impl.h
	gcc -Wall -std=c11 -g -c print_heap.c

get_mem_stats.o: get_mem_stats.c mem_impl.h
	gcc -Wall -std=c11 -g -c get_mem_stats.c

#test: getmem.o freemem.o get_mem_stats.o print_heap.o test.o 
#	gcc -std=c99 -Wall -g -o test test.o getmem.o freemem.o get_mem_stats.o print_heap.o

#test.o: test.c mem.h 
#		gcc -std=c99 -Wall -g -c test.c

dist: bench
	git log > ./git.log
		tar vcf hw6.tar ./*.c ./*.h ./README.md ./git.log ./Makefile

clean:
	rm -f *.o *~ git.log test hw6.tar bench