# 73. Set Matrix Zeroes

**Topic:** [Hash Table](../) · **Difficulty:** Medium

## Description

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its **entire row and column** to `0`s.

You must modify `matrix` **in place**.

## Examples

**Example 1:**

- Input: `matrix = [[1,1,1],[1,0,1],[1,1,1]]`
- Output: `[[1,0,1],[0,0,0],[1,0,1]]`

**Example 2:**

- Input: `matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]`
- Output: `[[0,0,0,0],[0,4,5,0],[0,3,1,0]]`

## Constraints

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

## Follow-up

An `O(mn)` extra copy is wasteful. `O(m + n)` extra arrays marking which rows/cols to clear is better.

**Constant extra space:** treat the **first row** and **first column** of `matrix` as two marker arrays (like two **implicit hash sets** of row/column indices that must become zero). Scan the interior `(1..m-1, 1..n-1)` for zeros and stamp `matrix[i][0]` and `matrix[0][j]`. Then zero marked rows/cols using those stamps. Because the first row/column entries may themselves need to be zeroed, keep two booleans `row0` and `col0` from an initial scan of the original first row/column, and apply them last.

Time **O(m n)**, extra space **O(1)**.

## Files in this folder

- `problem73.py` — Python solution
- `problem73.cpp` — C++ solution
