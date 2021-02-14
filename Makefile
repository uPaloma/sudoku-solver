output: findSol.o isvalid.o 
	gcc findSol.o isvalid.o -o output

findSol.o: findSol.c
	gcc -c -Wall -Werror -Wpedantic -std=c99 findSol.c

isvalid.o: isvalid.c
	gcc -c -Wall -Werror -Wpedantic -std=c99 isvalid.c

clean: 
	rm *.o output