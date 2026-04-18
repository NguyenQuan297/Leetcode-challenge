# 12. Integer to Roman

**Topic:** [Hash Table](../) · **Difficulty:** Medium

## Description

Roman numerals are formed by converting each decimal place value from highest to lowest. Seven symbols are used: `I` (1), `V` (5), `X` (10), `L` (50), `C` (100), `D` (500), `M` (1000).

Special **subtractive** forms are used when a place starts with 4 or 9: `IV`, `IX`, `XL`, `XC`, `CD`, `CM`. Symbols `I`, `X`, `C`, `M` may repeat at most three times in a row; `V`, `L`, `D` are not repeated.

Given an integer `num`, convert it to a Roman numeral string.

## Examples

**Example 1:**

- Input: `num = 3749`
- Output: `"MMMDCCXLIX"`
- Explanation: `3000 = MMM`, `700 = DCC`, `40 = XL`, `9 = IX`.

**Example 2:**

- Input: `num = 58`
- Output: `"LVIII"`
- Explanation: `50 = L`, `8 = VIII`.

**Example 3:**

- Input: `num = 1994`
- Output: `"MCMXCIV"`
- Explanation: `1000 = M`, `900 = CM`, `90 = XC`, `4 = IV`.

## Constraints

- `1 <= num <= 3999`

## Approach

**Greedy with a fixed ordered table:** precompute all values that can start a block (including subtractive pairs like `900 → CM`). Walk from largest to smallest; while `num >= value`, append the symbol and subtract. At most a constant number of steps for `num <= 3999`.

On **CPython**, this beats four **dict** lookups per test (hashing + string work) and usually ranks faster on LeetCode than digit→fragment hash maps. Time **O(1)**, space **O(1)** for the tables plus output length.

## Files in this folder

- `problem12.py` — Python solution
- `problem12.cpp` — C++ solution
