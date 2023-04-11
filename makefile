CC = gcc
CFLAGS = -g

build: main.o function.o
	$(CC) -o prg main.o function.o

clean:
	rm -f *.o
	rm -f *~
	rm -f $(NAME)
