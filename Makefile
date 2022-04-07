all:
	gcc -c hashtable.c -o hashtable.o
	gcc -Wall hashtable.o -lm main.c -o myht

clean:
	-rm -f *~ *.o

purge:
	-rm -f myht
