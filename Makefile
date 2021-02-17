output: IO.o findSol.o isvalid.o 
	gcc IO.o findSol.o isvalid.o -o output

IO.o: IO.c
	gcc -c -Wall -Werror -Wpedantic -std=c99 IO.c

findSol.o: findSol.c
	gcc -c -Wall -Werror -Wpedantic -std=c99 findSol.c

isvalid.o: isvalid.c
	gcc -c -Wall -Werror -Wpedantic -std=c99 isvalid.c

clean: 
	rm *.o output