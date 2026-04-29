# 115. Distinct Subsequences

**Topic:** [Dynamic Programming](../) · **Difficulty:** Hard

## Description

Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

## Examples

**Example 1:**

- Input: `s = "rabbbit"`, `t = "rabbit"`
- Output: `3`

**Example 2:**

- Input: `s = "babgbag"`, `t = "bag"`
- Output: `5`

## Constraints

- `1 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

## Approach

Use rolling 1D DP where `dp[j]` = number of ways to form `t[:j]` using `s[:i]`.

Iterate `s` left to right; for each character update `dp` **right to left** to avoid using the same `s[i]` twice:

- if `s[i-1] == t[j-1]`: `dp[j] += dp[j-1]`

Base: `dp[0] = 1` (empty `t` matched by any prefix of `s`).

Scanning right to left ensures `dp[j-1]` still reflects `s[:i-1]` when we read it (no overwrite issue).

Time complexity: **O(mn)**  
Space complexity: **O(n)** where `n = len(t)`

## Files in this folder

- `problem115.py` — Python solution
- `problem115.cpp` — C++ solution
