CCFLAGS=-Wall -Wextra -Wconversion -Wredundant-decls -Wshadow -Wno-unused-parameter -O3
CC=gcc

all: test

remake: clean all

%.cpp: %.c
	ln -fs $< $@

%.c.o: %.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

test: main_test.c.o ctest.h test.c.o
	$(CC) $(LDFLAGS) main_test.c.o test.c.o -o test

clean:
	rm -f test *.o