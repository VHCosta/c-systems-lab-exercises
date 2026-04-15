# C Systems Lab — Exercise Starters

Starter exercises for C Systems Lab.

Each exercise directory contains starter material for one exercise.
Many refreshed directories include:

- **`prompt.md`** — the exercise statement and requirements
- **`meta.json`** — metadata such as difficulty and compiler flags
- **Starter files** — stubs with `TODO` comments where you write your code

Some older directories still expose source files only while the repo is being
refreshed to the same layout.

Work through the exercises alongside the course, or use them independently.

---

## Structure

```text
chNN/exN_M/
  prompt.md     exercise statement            (refreshed exercises)
  meta.json     metadata (difficulty, flags)  (refreshed exercises)
  *.c / *.h     starter code or scaffolding
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

Version: 2026-04-15 | 48 exercises across 12 chapters
