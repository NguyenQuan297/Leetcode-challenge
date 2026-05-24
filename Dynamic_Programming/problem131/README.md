# 131. Palindrome Partitioning

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return all possible palindrome partitionings.

## Examples

**Example 1:**

- Input: `s = "aab"`
- Output: `[["a","a","b"],["aa","b"]]`

**Example 2:**

- Input: `s = "a"`
- Output: `[["a"]]`

## Constraints

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

## Approach

**DP precomputation + backtracking:**

1. Build a 2D boolean table `is_pal[i][j]` = `True` if `s[i..j]` is a palindrome:
   - Every single character is a palindrome.
   - `is_pal[i][j] = (s[i] == s[j]) and is_pal[i+1][j-1]` for length ≥ 2.
2. Backtrack from index `start`:
   - For each end index `j` from `start` to `n-1`, if `is_pal[start][j]` is `True`, append `s[start..j]` to the current path and recurse with `j+1`.
   - When `start == n`, record the current path.

The DP table removes repeated palindrome checks during backtracking, making each check O(1).

Time complexity: **O(n · 2^n)** — up to 2^n partitions, each of length O(n)  
Space complexity: **O(n²)** for the DP table

## Files in this folder

- `problem131.py` — Python solution
- `problem131.cpp` — C++ solution
