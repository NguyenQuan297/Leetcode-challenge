# 63. Unique Paths II

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

A robot starts at the top-left corner of an `m x n` grid with obstacles.

- `obstacleGrid[i][j] == 1` means an obstacle; `0` means free space.
- The robot can only move **right** or **down**.

Return the number of unique paths from top-left to bottom-right that avoid all obstacles.

## Examples

**Example 1:**

- Input: `obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]`
- Output: `2`

**Example 2:**

- Input: `obstacleGrid = [[0,1],[0,0]]`
- Output: `1`

## Constraints

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.

## Approach

Same 2D DP as problem 62, extended to handle obstacles:

- `dp[i][j] = 0` if `obstacleGrid[i][j] == 1`
- else `dp[i][j] = dp[i-1][j] + dp[i][j-1]`
- Base: `dp[0][0] = 1` if start is free, else `0`

Time complexity: **O(mn)**  
Space complexity: **O(mn)**

## Files in this folder

- `problem63.py` — Python solution
- `problem63.cpp` — C++ solution
