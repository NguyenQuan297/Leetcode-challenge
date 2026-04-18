# 76. Minimum Window Substring

**Topic:** [Hash Table](../) · **Difficulty:** Hard

## Description

Given two strings `s` and `t` of lengths `m` and `n`, return the **minimum window** substring of `s` such that every character in `t` (**including duplicates**) appears in the window with at least the same multiplicity.

If no such substring exists, return `""`.

The test data guarantees the answer is unique when it exists.

## Examples

**Example 1:**

- Input: `s = "ADOBECODEBANC"`, `t = "ABC"`
- Output: `"BANC"`

**Example 2:**

- Input: `s = "a"`, `t = "a"`
- Output: `"a"`

**Example 3:**

- Input: `s = "a"`, `t = "aa"`
- Output: `""`

## Constraints

- `m == s.length`, `n == t.length`
- `1 <= m, n <= 10^5`
- `s` and `t` consist of English letters (uppercase and lowercase).

## Follow-up

An **O(m + n)** algorithm: sliding window over `s` with two pointers. Maintain a **frequency map** of how many more of each character are still **required** from `t` (initial counts from `t`, decremented as characters enter the window). Track how many characters of `t` are still **unsatisfied** (`missing`); when it hits `0`, shrink the left edge while valid and record the shortest window.

## Files in this folder

- `problem76.py` — Python solution
- `problem76.cpp` — C++ solution
