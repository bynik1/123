CCFLAGS=-Wall -Wextra -Wconversion -Wredundant-decls -Wshadow -Wno-unused-parameter -O3
CC=gcc
CXX=g++

all: test

remake: clean all

%.cpp: %.c
	ln -fs $< $@

%.c.o: %.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<


test: main.c.o ctest.h mytests.c.o
	$(CC) $(LDFLAGS) main.c.o mytests.c.o -o test

test++: main_test.cpp.o ctest.h test.cpp.o
	$(CXX) $(LDFLAGS) main_test.cpp.o test.cpp.o -o test++

clean:
	rm -f test *.o