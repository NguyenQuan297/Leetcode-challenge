# 91. Decode Ways

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

A string of digits is decoded via the mapping `"1" -> 'A'`, `"2" -> 'B'`, ..., `"26" -> 'Z'`.

Return the number of ways to decode the string `s`. If no valid decoding exists, return `0`.

## Examples

**Example 1:**

- Input: `s = "12"`
- Output: `2`
- Explanation: `"AB"` (1 2) or `"L"` (12)

**Example 2:**

- Input: `s = "226"`
- Output: `3`
- Explanation: `"BZ"` (2 26), `"VF"` (22 6), or `"BBF"` (2 2 6)

**Example 3:**

- Input: `s = "06"`
- Output: `0`

## Constraints

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zeros.

## Approach

Use rolling 2-variable DP (instead of a full array):

- `prev2` = ways to decode `s[:i-2]`, `prev1` = ways to decode `s[:i-1]`
- For each position `i`:
  - **Single digit** `s[i-1]`: valid if `s[i-1] != '0'` → add `prev1`
  - **Two digits** `s[i-2:i]`: valid if `10 ≤ val ≤ 26` → add `prev2`

Time complexity: **O(n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem91.py` — Python solution
- `problem91.cpp` — C++ solution
