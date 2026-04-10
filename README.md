# C Systems Lab — Exercises

Starter files for the exercises in the [C Systems Lab Companion PDF](https://csystemslab.com).

Each directory maps to a chapter in the companion:

| Directory | Chapter |
|-----------|---------|
| `ch01/` | Setup and the Compilation Model |
| `ch02/` | Types, Operators, and Control Flow |
| `ch03/` | Pointers and the Memory Model |
| `ch04/` | Dynamic Memory |
| `ch05/` | Structs, Unions, and Bit Fields |
| `ch06/` | The C Preprocessor |
| `ch07/` | File I/O and System Calls |
| `ch08/` | Processes and Signals |
| `ch09/` | Sockets and Networking |
| `ch10/` | Concurrency |
| `ch11/` | Going Below C |

## Getting started

```bash
git clone https://github.com/VHCosta/c-systems-lab-exercises
cd c-systems-lab-exercises
```

Each exercise directory contains one or more `.c` files with `/* TODO: implement */`
markers where your code goes. The compile command is in the header comment of each file.

Example:

```bash
cd ch04/ex4_1
gcc -Wall -Wextra -Werror -std=c11 -g -o ex4_1 ex4_1.c && ./ex4_1
```

## Notes

- All exercises compile with `-std=c11 -Wall -Wextra -Werror`. Use the exact command
  in the file header.
- The companion PDF describes what each exercise asks you to implement.
- Full annotated solutions are included in the PDF + Solutions edition.
