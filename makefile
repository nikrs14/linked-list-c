ALL: main

main:	main.o encadeada.o
		gcc main.o encadeada.o -o main

main.o: main.c encadeada.c encadeada.h
		gcc -c main.c

encadeia.o: encadeada.c encadeada.h
		gcc -c encadeada.c

clean:
		rm -f *.o main