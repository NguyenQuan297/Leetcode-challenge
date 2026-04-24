# 10. Regular Expression Matching

**Topic:** [Dynamic Programming](../) · **Difficulty:** Hard

## Description

Given an input string `s` and a pattern `p`, implement regular expression matching with support for:

- `.` matches any single character.
- `*` matches zero or more of the preceding element.

Return `true` if the matching covers the **entire** string `s` (not partial), otherwise return `false`.

## Examples

**Example 1:**

- Input: `s = "aa"`, `p = "a"`
- Output: `false`

**Example 2:**

- Input: `s = "aa"`, `p = "a*"`
- Output: `true`

**Example 3:**

- Input: `s = "ab"`, `p = ".*"`
- Output: `true`

## Constraints

- `1 <= s.length <= 20`
- `1 <= p.length <= 20`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `.`, and `*`.
- For each `*`, there is always a valid preceding character.

## Approach

Use **2D DP** where `dp[i][j]` means `s[:i]` matches `p[:j]`.

- **Base:** `dp[0][0] = true`.
- **Empty string vs pattern with `*`:** if `p[j-1] == '*'`, then `dp[0][j] = dp[0][j-2]`.
- **Normal character / `.`:**  
  if `p[j-1] == s[i-1]` or `p[j-1] == '.'`, then `dp[i][j] = dp[i-1][j-1]`.
- **`*` case:** treat `x*` in two ways:
  - Use zero occurrence: `dp[i][j] = dp[i][j-2]`
  - Use one/more occurrence (if `x` matches `s[i-1]`): `dp[i][j] |= dp[i-1][j]`

Time complexity: **O(mn)**, space complexity: **O(mn)** where `m = len(s)`, `n = len(p)`.

## Files in this folder

- `problem10.py` — Python solution
- `problem10.cpp` — C++ solution
