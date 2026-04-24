# 32. Longest Valid Parentheses

**Topic:** [Dynamic Programming](../) · **Difficulty:** Hard

## Description

Given a string `s` containing only `'('` and `')'`, return the length of the longest valid (well-formed) parentheses substring.

## Examples

**Example 1:**

- Input: `s = "(()"`
- Output: `2`
- Explanation: The longest valid substring is `"()"`.

**Example 2:**

- Input: `s = ")()())"`
- Output: `4`
- Explanation: The longest valid substring is `"()()"`.

**Example 3:**

- Input: `s = ""`
- Output: `0`

## Constraints

- `0 <= s.length <= 3 * 10^4`
- `s[i]` is `'('` or `')'`.

## Approach

Use 1D DP where `dp[i]` is the length of the longest valid parentheses substring that **ends at index `i`**.

Only `')'` can end a valid substring:

- If `s[i - 1] == '('`, then `"...()"` pattern:
  - `dp[i] = (dp[i - 2] if i >= 2 else 0) + 2`
- Else `s[i - 1] == ')'`, try to connect with a matching `'('` before the previous valid block:
  - `prev = dp[i - 1]`
  - `j = i - prev - 1`
  - if `j >= 0` and `s[j] == '('`:
    - `dp[i] = prev + 2 + (dp[j - 1] if j >= 1 else 0)`

Track the maximum value across all `dp[i]`.

Time complexity: **O(n)**, space complexity: **O(n)**.

## Files in this folder

- `problem32.py` — Python solution
- `problem32.cpp` — C++ solution
