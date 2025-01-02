CC = gcc
CFLAGS = -Wall -O2 -g
LDFLAGS = -lm

lab3d: main.o sec.o
	$(CC) $(CFLAGS) -o lab3d main.o sec.o $(LDFLAGS)

main.o: main.c sec.h
	$(CC) $(CFLAGS) -c main.c -o main.o

sec.o: sec.c sec.h
	$(CC) $(CFLAGS) -c sec.c -o sec.o

clean:
	rm -f *.o lab3d
