# 240. Search a 2D Matrix II

**Topic:** [Binary Search](../) · **Difficulty:** Medium

## Description

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has these properties:

1. Integers in each row are sorted in ascending order from left to right.
2. Integers in each column are sorted in ascending order from top to bottom.

## Examples

**Example 1:**

- Input: `matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]`, `target = 5`
- Output: `true`

**Example 2:**

- Input: same matrix, `target = 20`
- Output: `false`

## Constraints

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= n, m <= 300`
- `-10^9 <= matrix[i][j] <= 10^9`
- `-10^9 <= target <= 10^9`

## Approach

**Binary search each row** (rows are sorted): **O(m log n)**. Because columns are also sorted, if `row[0] > target` then every row below is larger — stop. If `row[-1] < target`, that row cannot contain `target` — skip.

(Another classic solution walks from the top-right corner in **O(m + n)** time; this folder uses the binary-search-on-rows version.)

## Difference from problem 74

In **74**, the matrix behaves like one long sorted array (row `i+1` starts after row `i` ends). Here, only row-wise and column-wise order holds, so you cannot binary-search a single flat index the same way.

## Files in this folder

- `problem240.py` — Python solution
- `problem240.cpp` — C++ solution
