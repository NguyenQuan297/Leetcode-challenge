# 49. Group Anagrams

**Topic:** [Sorting](../) · **Difficulty:** Medium

## Description

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

## Examples

**Example 1:**

- Input: `strs = ["eat","tea","tan","ate","nat","bat"]`
- Output: `[["bat"],["nat","tan"],["ate","eat","tea"]]`
- Explanation: Strings that are anagrams share the same letters with the same counts.

**Example 2:**

- Input: `strs = [""]`
- Output: `[[""]]`

**Example 3:**

- Input: `strs = ["a"]`
- Output: `[["a"]]`

## Constraints

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

## Files in this folder

- `problem49.py` — Python solution
- `problem49.cpp` — C++ solution
