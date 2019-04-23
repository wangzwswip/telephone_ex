telephone:list.o address.o
	gcc -g -o telephone list.o address.o
list.o:list.c list.h
	gcc -g -c list.c
address.o:address.c list.c
	gcc -g -c address.c
clean:
	rm -rf *.o