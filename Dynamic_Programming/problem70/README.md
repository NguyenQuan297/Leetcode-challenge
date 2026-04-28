# 70. Climbing Stairs

**Topic:** [Dynamic Programming](../) · **Difficulty:** Easy

## Description

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can climb `1` or `2` steps. Return the number of distinct ways to climb to the top.

## Examples

**Example 1:**

- Input: `n = 2`
- Output: `2`
- Explanation: `1+1`, `2`

**Example 2:**

- Input: `n = 3`
- Output: `3`
- Explanation: `1+1+1`, `1+2`, `2+1`

## Constraints

- `1 <= n <= 45`

## Approach

Classic Fibonacci DP:

- `dp[1] = 1`, `dp[2] = 2`
- `dp[i] = dp[i-1] + dp[i-2]`

Only the two previous values are needed, so use two variables instead of a full array.

Time complexity: **O(n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem70.py` — Python solution
- `problem70.cpp` — C++ solution
