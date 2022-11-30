# Romain LANCELOT - 2ESGI A4

executable : 52.o arraylist.o hashmap.o
	gcc -o executable 52.o arraylist.o hashmap.o

52.o : 52.c
	gcc -c 52.c

arraylist.o : arraylist.c arraylist.h
	gcc -c arraylist.c

hashmap.o : hashmap.c hashmap.h
	gcc -c hashmap.c

clean :
	rm -Rf *.o *.gch executable

