# Separate debugging symbols with ELF (Linux) binaries
This repository is a tutorial on how to separate the debugging symbols from the final executable, and still be able to debug it.

## Requirements
- C compiler (e.g. [Clang](https://clang.llvm.org/))
- [Make](https://www.gnu.org/software/make/)
- [binutils](https://www.gnu.org/software/binutils/)

Note: some of this tutorial also applies to [MinGW](https://mingw-w64.org/).

## Instructions
First, the executable is built, and it contains the debugging symbols.

```sh
clang -g main.c -o main
```

Then the debugging symbols are extracted into a new file.

```sh
objcopy --only-keep-debug main main.dbg
```

The final executable is stripped of debugging symbols.

```sh
objcopy --strip-debug main
```

Additionally, a debug link can be added to allow GDB to find the file with the debugging symbols.

```sh
objcopy --add-gnu-debuglink=main.dbg main
```

If everything works well GDB should say something like:

```
Reading symbols from main...Reading symbols from /some/directory/separate-symbols/main.dbg...done.
done.
```

You can also run GDB and add the file manually:

```bash
(gdb) exec-file main
(gdb) symbol-file main.dbg
```

## Credits
Inspired by [this answer](https://stackoverflow.com/a/866731/) on StackOverflow.

Also check the [GDB manual](https://sourceware.org/gdb/onlinedocs/gdb/Separate-Debug-Files.html).
