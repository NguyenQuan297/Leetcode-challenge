# 44. Wildcard Matching

**Topic:** [Dynamic Programming](../) · **Difficulty:** Hard

## Description

Given an input string `s` and a pattern `p`, implement wildcard matching with:

- `?` matches any single character.
- `*` matches any sequence of characters (including empty).

Return `true` if the pattern matches the **entire** string.

## Examples

**Example 1:**

- Input: `s = "aa"`, `p = "a"`
- Output: `false`

**Example 2:**

- Input: `s = "aa"`, `p = "*"`
- Output: `true`

**Example 3:**

- Input: `s = "cb"`, `p = "?a"`
- Output: `false`

## Constraints

- `0 <= s.length, p.length <= 2000`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `?`, or `*`.

## Approach

Use DP where `dp[i][j]` means `s[:i]` matches `p[:j]`.

- Base: `dp[0][0] = true`
- Empty string with pattern prefix:
  - if `p[j-1] == '*'`, then `dp[0][j] = dp[0][j-1]`
- Transition:
  - if `p[j-1] == '*'`:  
    `dp[i][j] = dp[i][j-1]` (star = empty) or `dp[i-1][j]` (star consumes one char)
  - else if `p[j-1] == '?'` or `p[j-1] == s[i-1]`:  
    `dp[i][j] = dp[i-1][j-1]`

Since `m, n` can be up to 2000, use **1D rolling DP** to reduce space from `O(mn)` to `O(n)`.

Time complexity: **O(mn)**  
Space complexity: **O(n)**

## Files in this folder

- `problem44.py` — Python solution
- `problem44.cpp` — C++ solution
