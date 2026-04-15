# Exercise 1.2 — Decode a linker error

## Goal

Practice distinguishing declaration vs. definition, missing object files vs.
missing libraries, and the exact symbol that each failing link step cannot
resolve.

## Starter files

- `vector.h`
- `vector.c`
- `main.c`

## Tasks

1. For `gcc main.c vector.c -lm -o prog`, state which symbol the linker cannot
   resolve and explain why this is a missing definition, not a missing
   declaration.
2. Implement `vec2_add` in `vector.c` and verify the program compiles and
   produces `length = 7.21`.
3. Try `gcc main.c -lm -o prog` without `vector.c`.
   - What error do you get?
   - Which symbols are missing?
4. Try `gcc main.c vector.c -o prog` without `-lm`.
   - What error do you get?
   - Why is this a missing-library problem rather than a bug in `vector.h`?

## Compile and run

```sh
gcc -std=c11 -Wall -Wextra -Werror -O1 -o ex1_2 main.c vector.c -lm && ./ex1_2
```

Expected output after fixing `vec2_add`:

```text
length = 7.21
```
