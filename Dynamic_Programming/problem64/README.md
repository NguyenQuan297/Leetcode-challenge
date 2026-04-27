# 64. Minimum Path Sum

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given an `m x n` grid filled with non-negative numbers, find a path from top-left to bottom-right that minimizes the sum of all numbers along its path.

You can only move **right** or **down** at any point.

## Examples

**Example 1:**

- Input: `grid = [[1,3,1],[1,5,1],[4,2,1]]`
- Output: `7`
- Explanation: Path `1 → 3 → 1 → 1 → 1` minimizes the sum.

**Example 2:**

- Input: `grid = [[1,2,3],[4,5,6]]`
- Output: `12`

## Constraints

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 200`
- `0 <= grid[i][j] <= 200`

## Approach

In-place DP on the input grid:

- First row: accumulate left → right
- First column: accumulate top → bottom
- Inner cells: `grid[i][j] += min(grid[i-1][j], grid[i][j-1])`

Answer is `grid[m-1][n-1]`.

Modifying in-place avoids allocating a separate `dp` array.

Time complexity: **O(mn)**  
Space complexity: **O(1)** extra

## Files in this folder

- `problem64.py` — Python solution
- `problem64.cpp` — C++ solution
