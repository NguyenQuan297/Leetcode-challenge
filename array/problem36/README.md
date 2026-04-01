# 36. Valid Sudoku

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Determine if a `9 × 9` Sudoku board is **valid**. Only the **filled** cells need to be validated according to these rules:

1. Each **row** must contain the digits `1-9` without repetition.
2. Each **column** must contain the digits `1-9` without repetition.
3. Each of the nine **`3 × 3` sub-boxes** must contain the digits `1-9` without repetition.

A partially filled board may be valid even if it is not solvable. Only filled cells are checked.

## Examples

**Example 1:**

- Input: `board` as a `9 × 9` grid of characters (`'1'`-`'9'` or `'.'`) matching the classic partially filled puzzle (see LeetCode for full grid).
- Output: `true`

**Example 2:**

- Input: Same as Example 1, but the top-left cell is changed from `5` to `8`, creating two `8`s in the top-left `3 × 3` sub-box.
- Output: `false`

## Constraints

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit `'1'`-`'9'` or `'.'`.

## Files in this folder

- `problem36.py` — Python solution (`List[List[str]]`)
- `problem36.cpp` — C++ solution (`vector<vector<char>>`)
