# 17. Letter Combinations of a Phone Number

**Topic:** [Hash Table](../) · **Difficulty:** Medium

## Description

Given a string `digits` containing digits from `2`–`9`, return all possible letter combinations that the number could represent (phone keypad mapping). Return the answer in **any order**.

Digit `1` does not map to letters. The mapping follows a standard telephone keypad (`2`→`abc`, `3`→`def`, …, `9`→`wxyz`).

## Examples

**Example 1:**

- Input: `digits = "23"`
- Output: `["ad","ae","af","bd","be","bf","cd","ce","cf"]`

**Example 2:**

- Input: `digits = ""`
- Output: `[]`

**Example 3:**

- Input: `digits = "2"`
- Output: `["a","b","c"]`

## Constraints

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

## Approach

Store the digit → letters mapping in a **hash table** (`dict` in Python, `unordered_map<char, string>` in C++). Start with `[""]` and **extend** each partial string by every letter for the next digit (Cartesian product by layers). At most `4^4` combinations in the worst case; time **O(4^n · n)** for `n = len(digits)` in the worst keypad branching, space for the output list.

## Files in this folder

- `problem17.py` — Python solution
- `problem17.cpp` — C++ solution
