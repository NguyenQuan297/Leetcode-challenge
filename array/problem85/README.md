# 85. Maximal Rectangle

**Topic:** [Array](../) · **Difficulty:** Hard

## Description

Given a binary matrix of `'0'`s and `'1'`s, find the largest rectangle containing only `'1'`s and return its area.

## Examples

**Example 1:**

- Input: `matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]`
- Output: `6`

**Example 2:**

- Input: `matrix = [["0"]]`
- Output: `0`

**Example 3:**

- Input: `matrix = [["1"]]`
- Output: `1`

## Constraints

- `1 <= rows, cols <= 200`
- `matrix[i][j]` is `'0'` or `'1'`.

## Approach

Reduce to **problem 84 (Largest Rectangle in Histogram)** applied row-by-row:

- Maintain a `heights` array of length `cols`.
- For each row `r` and column `c`:
  - If `matrix[r][c] == '1'`: `heights[c] += 1` (extend the bar upward).
  - Else: `heights[c] = 0` (bar is broken by a `'0'`).
- After updating `heights`, run the **monotonic stack** histogram algorithm on it and update the global best.

The monotonic stack algorithm used is identical to problem 84 (O(cols) per row, inline sentinel at index `cols`).

Time complexity: **O(rows × cols)**  
Space complexity: **O(cols)** for the heights array and stack

## Files in this folder

- `problem85.py` — Python solution
- `problem85.cpp` — C++ solution
