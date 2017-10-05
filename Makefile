CFLAGS += -g -Og
CFLAGS += -Wall -Wextra -Werror

.PHONY: all test clean

all: test

test: main.final main.dbg
	gdb --quiet main.final

clean:
	rm --force main.dbg main.final main

main.final: main
	objcopy --strip-debug $< $@
	objcopy --add-gnu-debuglink=main.dbg $@

main.dbg: main
	objcopy --only-keep-debug $< $@
