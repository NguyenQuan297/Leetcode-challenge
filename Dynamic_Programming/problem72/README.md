# 72. Edit Distance

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given two strings `word1` and `word2`, return the minimum number of operations to convert `word1` to `word2`.

Allowed operations:

- Insert a character
- Delete a character
- Replace a character

## Examples

**Example 1:**

- Input: `word1 = "horse"`, `word2 = "ros"`
- Output: `3`

**Example 2:**

- Input: `word1 = "intention"`, `word2 = "execution"`
- Output: `5`

## Constraints

- `0 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of lowercase English letters.

## Approach

Use rolling 1D DP to reduce space from `O(mn)` to `O(n)`:

- `dp[j]` represents the edit distance between `word1[:i]` and `word2[:j]`
- For each character `word1[i-1]`:
  - save `prev = dp[j-1]` before overwriting (diagonal value)
  - if characters match: `dp[j] = prev` (no operation)
  - else: `dp[j] = 1 + min(prev, dp[j], dp[j-1])`
    - `prev` = replace, `dp[j]` = delete from word1, `dp[j-1]` = insert

Time complexity: **O(mn)**  
Space complexity: **O(n)**

## Files in this folder

- `problem72.py` — Python solution
- `problem72.cpp` — C++ solution
