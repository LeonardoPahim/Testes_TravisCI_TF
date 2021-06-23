# Author: Rafael Garibotti
MKDIR = mkdir -p
CLEANUP = rm -f
MKDIR = mkdir -p
TARGET_EXTENSION=.out
##### Compiler options #####
C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=Unity

GCC = gcc
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

##### Custom Flags #####
GCCFLAGS = -g -Wall -Wfatal-errors
GCCFLAGS += -Wstrict-prototypes
GCCFLAGS += -Wold-style-definition
GCCFLAGS += -Wdiscarded-qualifiers
CFLAGS += -Wstrict-prototypes


##### Project specific libraries #####
UNITY_ROOT=Unity
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

all: clean compile cov runcov valgrind cppcheck clean

compile:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) -fsanitize=address -Wold-style-definition $(SRC_FILES) $(SRC_FILES_UNITY) -o $(TARGET1)

crypt: $(SRC_FILES)
		$(CC) $(CFLAGS) $^
		$(CC) *.o -o app
		rm -rf *.o
run:
	- ./$(TARGET1)

valgrind:
	#Memcheck
	- valgrind --leak-check=full --show-leak-kinds=all ./cov -v

	#Cachegrind
	#- valgrind --tool=cachegrind ./cov -v

	#Callgrind
	#- valgrind --tool=callgrind ./cov -v	
	
	#Massif
	#- valgrind --tool=massif ./cov -v

	#Helgrind
	#- valgrind --tool=helgrind ./cov -v

cppcheck:
	- cppcheck --enable=all --suppress=missingIncludeSystem $(SRC_FILES)

cov: 
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) -fprofile-arcs -ftest-coverage $(SRC_FILES_UNITY) $(SRC_FILES) -o $@

runcov:
	- ./cov
	- gcov -b crypt.c
	- gcov -b blowfish.gcda
	- gcov -b aes.gcda
	- gcov -b xtea.gcda

clean:
	$(CLEANUP) $(TARGET1)	
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov cachegrind* callgrind* massif*

##### General commands #####
#crypt: $(SRC_FILES)
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

