# C Systems Lab — Exercise Starters

Starter exercises for C Systems Lab.

Each directory contains a complete exercise with:

- **`prompt.md`** — the exercise statement and requirements
- **Starter files** — stubs with `TODO` comments where you write your code

Work through the exercises alongside the course, or use them independently.

---

## Structure

```
chNN/exN_M/
  prompt.md     exercise statement
  meta.json     metadata (difficulty, tags, compile flags)
  *.c / *.h     starter code with TODO stubs
```

## Building

Each exercise lists its compile command in `prompt.md`. Most follow this pattern:

```sh
gcc -std=c11 -Wall -Wextra -Werror -o exN_M exN_M.c && ./exN_M
```

## Want the full code pack?

The paid C Systems Lab code pack includes full worked solutions, annotated
explanations, and extended projects for every exercise.

**Available now:** [vhcosta.gumroad.com/l/c-systems-lab](https://vhcosta.gumroad.com/l/c-systems-lab)

---

Version: 2026-04-11 | 43 exercises across 11 chapters
