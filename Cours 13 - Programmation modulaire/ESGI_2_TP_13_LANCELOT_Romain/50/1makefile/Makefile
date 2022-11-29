# Romain LANCELOT - 2ESGI A4

executable : 50.o module.o
	gcc -o executable 50.o module.o -lm

50.o : 50.c
	gcc -c 50.c

module.o : module.c module.h
	gcc -c module.c

clean :
	rm -Rf *.o

