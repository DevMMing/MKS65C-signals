compile:signals.o
	gcc signals.o
run:
	./a.out
clean:
	rm *.o ./a.out file.txt
signals.o: signals.c
	gcc -c signals.c
