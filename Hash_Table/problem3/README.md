# 3. Longest Substring Without Repeating Characters

**Topic:** [Hash Table](../) · **Difficulty:** Medium

## Description

Given a string `s`, find the length of the **longest substring** without repeating characters.

## Examples

**Example 1:**

- Input: `s = "abcabcbb"`
- Output: `3`
- Explanation: The answer is `"abc"`, with the length of `3`.

**Example 2:**

- Input: `s = "bbbbb"`
- Output: `1`
- Explanation: The answer is `"b"`, with the length of `1`.

**Example 3:**

- Input: `s = "pwwkew"`
- Output: `3`
- Explanation: The answer is `"wke"`, with the length of `3`. Notice that the answer must be a substring; `"pwke"` is a subsequence and not a substring.

## Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

## Approach

Use a **sliding window** `[left, right]` and a **hash map** from character to its **last index** in the string.

Expand `right` each step. If the current character was seen at an index `>= left`, move `left` to `last[char] + 1` to drop the duplicate from the window. Update `last[char]` and track the maximum window length `right - left + 1`.

Time **O(n)**, space **O(min(n, |Σ|))** where `Σ` is the character alphabet in use.

## Files in this folder

- `problem3.py` — Python solution
- `problem3.cpp` — C++ solution
