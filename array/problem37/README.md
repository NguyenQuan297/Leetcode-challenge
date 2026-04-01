# 37. Sudoku Solver

**Topic:** [Array](../) · **Difficulty:** Hard

## Description

Write a program to solve a Sudoku puzzle by filling the empty cells.

A Sudoku solution must satisfy:

1. Each **row** contains digits `1`–`9` exactly once.
2. Each **column** contains digits `1`–`9` exactly once.
3. Each of the nine **`3 × 3` sub-boxes** contains digits `1`–`9` exactly once.

The character `'.'` indicates empty cells.

The input board is modified **in place**. The solution is **guaranteed** to be unique.

## Example

**Input:** `board` (see LeetCode for full `9 × 9` grid of characters).

**Output:** `board` fully filled with the unique solution.

## Constraints

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit `'1'`-`'9'` or `'.'`.

## Files in this folder

- `problem37.py` — Python solution
- `problem37.cpp` — C++ solution
