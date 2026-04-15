# Exercise 1.4 — Static vs dynamic link size

## Goal

Compare what changes when the same non-trivial program is linked dynamically
versus statically.

## Starter file

- `measure.c`

## Tasks

1. Compile dynamically:

```sh
gcc -O2 -o measure_dyn measure.c -lm
```

2. Compile statically:

```sh
gcc -O2 -static -o measure_static measure.c -lm
```

3. Report:
   - binary sizes via `ls -lh`
   - shared dependencies via `ldd`
   - whether the static binary runs without any `.so` files present
4. Run `objdump -h measure_dyn | grep -E "\\.text|\\.data|\\.bss"` and the same
   on `measure_static`. How much larger is each section?
5. Bonus: run `strip measure_static` and report the new size. What did `strip`
   remove?

## Notes

- Some Linux distributions make fully static glibc builds awkward or
  unsupported. If `gcc -static` fails on your machine, record the exact error
  and explain what dependency is missing.
- `time(NULL)` changes on every run, so only the `sqrt(2)` line is stable.
