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

Decompose `num` into four decimal digits: thousands, hundreds, tens, and ones. For each place, use a **hash map** (digit `0`–`9` → Roman substring for that place only). Concatenate the four lookups. Each table has fixed size; lookups are **O(1)** per digit, overall **O(1)** for `num <= 3999`, space **O(1)**.

## Files in this folder

- `problem12.py` — Python solution
- `problem12.cpp` — C++ solution
