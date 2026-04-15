#!/usr/bin/env sh

# Exercise 1.3 — Build flags audit
#
# Fill in your answers below as comments.
#
# Command under review:
# gcc -std=c11 -Wall -Wextra -Wpedantic -O2 -g \
#     -fstack-protector-strong -D_FORTIFY_SOURCE=2 \
#     -o prog main.c
#
# TODO: explain -std=c11
# TODO: explain -Wall
# TODO: explain -Wextra
# TODO: explain -Wpedantic
# TODO: explain -O2
# TODO: explain -g
# TODO: explain -fstack-protector-strong
# TODO: explain -D_FORTIFY_SOURCE=2
#
# TODO: explain why -O2 and -g are said to conflict
# TODO: add one flag that makes implicit-function-declaration a hard error
# TODO: explain what _FORTIFY_SOURCE=2 actually does
