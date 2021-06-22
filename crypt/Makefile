# Author: Rafael Garibotti


##### Compiler options #####

CC = gcc
CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

##### Project specific libraries #####
UNITY_ROOT=../Unity
CLEANUP = rm -f
MKDIR = mkdir -p
TARGET_EXTENSION=.out
TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION) 
SRC_FILES += $(wildcard src/*.c)
SRC_FILES_UNITY =\
	$(UNITY_ROOT)/src/unity.c \
	$(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
	test/CryptTest.c \
	test/test_runners/CryptTest_Runner.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS= 

all: clean compile run

compile:
	$(CC) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) $(SRC_FILES_UNITY) -o $(TARGET1)

run:
	- ./$(TARGET1)

##### General commands #####
#compile: 
#	$(SRC_FILES)
#	$(CC) $(CFLAGS) $^
#	$(CC) *.o -o app
#	rm -rf *.o

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
#$(CLEANUP) $(TARGET1)	
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov cachegrind* callgrind*

