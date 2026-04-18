# 13. Roman to Integer

**Topic:** [Hash Table](../) · **Difficulty:** Easy

## Description

Roman numerals use seven symbols `I, V, X, L, C, D, M` with fixed values. Numerals are usually written **largest to smallest** left to right. When a smaller value appears **before** a larger one (e.g. `IV`, `IX`, `XL`, `XC`, `CD`, `CM`), that pair uses **subtraction** (e.g. `IV` = 4).

Given a valid Roman numeral string `s`, convert it to an integer.

## Examples

**Example 1:**

- Input: `s = "III"`
- Output: `3`

**Example 2:**

- Input: `s = "LVIII"`
- Output: `58`
- Explanation: `L = 50`, `V = 5`, `III = 3`.

**Example 3:**

- Input: `s = "MCMXCIV"`
- Output: `1994`
- Explanation: `M = 1000`, `CM = 900`, `XC = 90`, `IV = 4`.

## Constraints

- `1 <= s.length <= 15`
- `s` contains only `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
- `s` is a valid Roman numeral in the range `[1, 3999]`.

## Approach

Map each symbol to its value (**C++:** `unordered_map`; **Python:** a small **128-slot table** keyed by `ord(c)` so each step is integer indexing instead of hashing a one-character string).

**Python (faster constant factors):** build a **128-slot tuple** once (tuple indexing, no per-call list setup). Convert `s` to **ASCII `bytes`**, loop **indices backward** (`while i:`), and use `T[b[i]]` so each step avoids one-char strings and `reversed()` iterator overhead. Same subtract rule with `prev` as the right-to-left scan above.

**Left-to-right variant:** same map, compare current to next symbol (as in the C++ file). Time **O(n)**, space **O(1)**.

## Files in this folder

- `problem13.py` — Python solution
- `problem13.cpp` — C++ solution
