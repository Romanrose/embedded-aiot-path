CC ?= gcc
CFLAGS ?= -O2 -Wall -Wextra

all: hello

hello: hello.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f hello

