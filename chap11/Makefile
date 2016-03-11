
all: hello.o
	gcc hello.o -o hello 

hello.o: hello.c
	gcc -c -g -Wall hello.c

clean:
	rm -f hello.o hello
