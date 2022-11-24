executable : 50.o triangle.o point.o
	gcc -o executable 50.o triangle.o point.o -lm

50.o : 50.c
	gcc -c 50.c

triangle.o : triangle.c triangle.h
	gcc -c triangle.c

point.o : point.c point.h
	gcc -c point.c

clean :
	rm -Rf *.o

