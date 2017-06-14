replace: replace_blank.o io.o
	cc -g -o replace replace_blank.o io.o

replace_blank.o: ../commons/io.h replace_blank.c
	cc -g -c replace_blank.c

io.o: ../commons/io.h ../commons/io.c
	cc -g -c ../commons/io.c

clean:
	rm replace replace_blank.o io.o
