# 62. Unique Paths

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

A robot starts at the top-left corner of an `m x n` grid and wants to reach the bottom-right corner.

The robot can only move:

- right
- down

Return the number of unique paths from start to finish.

## Examples

**Example 1:**

- Input: `m = 3, n = 7`
- Output: `28`

**Example 2:**

- Input: `m = 3, n = 2`
- Output: `3`

## Constraints

- `1 <= m, n <= 100`

## Approach

Use 2D DP where `dp[i][j]` is the number of ways to reach cell `(i, j)`.

- First row: only from left => all `1`
- First column: only from top => all `1`
- Transition for inner cells:
  - `dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`

Answer is `dp[m - 1][n - 1]`.

Time complexity: **O(mn)**  
Space complexity: **O(mn)**

## Files in this folder

- `problem62.py` — Python solution
- `problem62.cpp` — C++ solution
