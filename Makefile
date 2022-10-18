run: graph.o main.o
	gcc graph.o main.o -o run

graph.o: graph.c graph.h
	gcc -c graph.c

main.o: main.o
	gcc -c main.c

clean:
	rm *.o run
