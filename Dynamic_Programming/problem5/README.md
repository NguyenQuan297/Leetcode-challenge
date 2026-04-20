# 5. Longest Palindromic Substring

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given a string `s`, return the **longest palindromic substring** in `s`.

## Examples

**Example 1:**

- Input: `s = "babad"`
- Output: `"bab"`
- Explanation: `"aba"` is also a valid answer.

**Example 2:**

- Input: `s = "cbbd"`
- Output: `"bb"`

## Constraints

- `1 <= s.length <= 1000`
- `s` consists of only digits and English letters.

## Approach

**Expand around center:** A palindrome mirrors around its center. There are **2n − 1** centers: index `i` (odd length, `"aba"`) and the gap `(i, i+1)` (even length, `"abba"`). From each center, expand outward while `s[left] == s[right]` and keep the longest span.

Same **O(n²)** worst-case time as filling an interval DP table, but **O(1)** extra space (no `n × n` boolean grid), fewer allocations, and better cache behavior—usually **faster on LeetCode** than naive 2D DP.

*(Classic 2D DP: `dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]`; can be compressed to **O(n)** space with careful order, but expand-from-center is simpler and often quicker in practice.)*

## Files in this folder

- `problem5.py` — Python solution
- `problem5.cpp` — C++ solution
