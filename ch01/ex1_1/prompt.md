# Exercise 1.1 — Trace the four stages by hand

## Goal

Walk a small two-file C program through preprocessing, compilation, assembly,
and linking, and identify what each stage produces.

## Starter files

- `util.h`
- `util.c`
- `main.c`

## Tasks

1. Preprocess: `gcc -E main.c -o main.i`
   - Find the `SQUARE(5)` expansion.
   - Find the `global` variable in `main.i`.
   - Note roughly how many total lines were produced.
2. Compile to assembly: `gcc -S -O0 main.c`
   - Find the call to `add` in `main.s`.
   - Identify which register carries the return value.
3. Assemble: `gcc -c main.c util.c`
   - Run `nm main.o` and `nm util.o`.
   - Which symbols are `U` in `main.o`? Which are `T`?
4. Link: `gcc main.o util.o -o prog && ./prog`
   - Run `nm prog` and find `add`.
   - What happened to `printf`?
5. Write one sentence per stage describing what disappeared or was resolved.

## Compile and run

```sh
gcc -std=c11 -Wall -Wextra -Werror -O1 -o ex1_1 main.c util.c && ./ex1_1
```

Expected output:

```text
add(3,4)  = 7
SQUARE(5) = 25
global    = 42
```
