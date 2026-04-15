# Exercise 1.3 — Build flags audit

## Goal

Explain what each flag in a realistic `gcc` invocation does, what problem it
addresses, and whether you would keep it in a development build, a release
build, or both.

## Starter file

- `build_flags_audit.sh`

## Tasks

Audit this command:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic -O2 -g \
    -fstack-protector-strong -D_FORTIFY_SOURCE=2 \
    -o prog main.c
```

For each flag: explain

1. what it does
2. what class of bug or problem it addresses
3. whether it belongs in a development build, release build, or both

Then answer:

1. Why are `-O2` and `-g` often said to conflict, and when is the combination
   still useful?
2. Add one flag that would turn an implicit-function-declaration warning into a
   hard error. Why might you want that in CI?
3. What does `-D_FORTIFY_SOURCE=2` actually do?

Record your answers as comments in `build_flags_audit.sh`.
