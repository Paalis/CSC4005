trap: trap.o traprule.o functions.o
	mpicc -o trap trap.o traprule.o functions.o
	rm *.o

trap.o: 
	mpicc -c trap.c

functions.o:
	mpicc -c functions.c

traprule.o: 
	mpicc -c traprule.c