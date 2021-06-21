# Author: Rafael Garibotti

##### Compiler options #####
CC = gcc
CFLAGS = -c -Wall

##### Project specific libraries #####
SRC_FILES += $(wildcard src/*.c)

##### General commands #####
all: $(SRC_FILES)
	$(CC) $(CFLAGS) $^
	$(CC) *.o -o app
	rm -rf *.o

#all: app
	
#app: main.o xtea.o aes.o blowfish.o
#	$(CC) main.o xtea.o aes.o blowfish.o -o app
#	rm -rf *.o

#main.o: src/main.c
#	$(CC) $(CFLAGS) $^

#xtea.o: src/xtea.c
#	$(CC) $(CFLAGS) $^

#aes.o: src/aes.c
#	$(CC) $(CFLAGS) $^
	
#blowfish.o: src/blowfish.c
#	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o app