all:
	gcc -c hashtable.c -o hashtable.o
	gcc -Wall hashtable.o -lm main.c -o myht

clean:
	-rm -f *~ *.o

purge:
	-rm -f myht

test:
	echo 'Teste 1...'
	./myht < teste1.in > teste.out
	diff teste.out teste1.out
	
	echo 'Teste 2...'
	./myht < teste2.in > teste.out
	diff teste.out teste2.out
	
	echo 'Teste 3...'
	./myht < teste3.in > teste.out
	diff teste.out teste3.out
	
	echo 'Teste 4...'
	./myht < teste4.in > teste.out
	diff teste.out teste4.out
