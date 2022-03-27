output: array.o linked-list.o queue.o
	gcc array.o linked-list.o queue.o -o output

array.o: src/array.c
	gcc -c src/array.c

linked-list.o: src/linked-list.c include/linked-list.h
	gcc -c src/linked-list.c

queues.o: src/queue.c include/queue.h
	gcc -c src/queue.c

clean:
	rm *.o output
