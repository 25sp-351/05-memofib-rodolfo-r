CC=gcc
CFLAGS=-Wall -Wextra

all: fib test_fib

fib: fib.c fib.h
	$(CC) $(CFLAGS) -o fib fib.c

test_fib: test_fib.c fib.c fib.h memo.c memo.h
	$(CC) $(CFLAGS) -DTESTING -o test_fib test_fib.c fib.c memo.c

test: test_fib
	./test_fib

clean:
	rm -f fib test_fib