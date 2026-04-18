# 30. Substring with Concatenation of All Words

**Topic:** [Hash Table](../) · **Difficulty:** Hard

## Description

You are given a string `s` and an array `words` where every string in `words` has the **same length**.

A **concatenated substring** is a substring of `s` that is exactly the concatenation of each string in `words` in **some order** (a permutation), with each word used exactly as many times as it appears in `words`.

Return all **starting indices** of such substrings in `s`. The answer may be in any order.

## Examples

**Example 1:**

- Input: `s = "barfoothefoobarman"`, `words = ["foo","bar"]`
- Output: `[0,9]`
- Explanation: `"barfoo"` at `0` and `"foobar"` at `9`.

**Example 2:**

- Input: `s = "wordgoodgoodgoodbestword"`, `words = ["word","good","best","word"]`
- Output: `[]`

**Example 3:**

- Input: `s = "barfoofoobarthefoobarman"`, `words = ["bar","foo","the"]`
- Output: `[6,9,12]`

## Constraints

- `1 <= s.length <= 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `s` and `words[i]` consist of lowercase English letters.

## Approach

Let `w = len(words[0])` and `k = len(words)`.

1. **Target frequencies:** count how many times each word must appear using a **hash map** `need` (`Counter` / `unordered_map`).
2. **Sliding window on word-aligned chunks:** for each starting offset `0 .. w-1`, scan indices `offset, offset+w, offset+2w, ...` and treat each length-`w` slice as one “word slot”.
3. Maintain **`cur`** (current window counts) and how many slots are filled. If a slice is not in `need`, reset the window. If `cur[word] > need[word]`, shrink from **`left`** one `w`-sized step at a time until counts match.
4. When the window has exactly `k` slots and all counts match `need`, record **`left`**, then advance `left` by one word (same as sliding one concatenation forward).

This avoids checking every index naively and keeps work proportional to scanning `s` with `w` offsets. Time about **O(len(s) * w)** in the worst case for this pattern, space **O(k)** for the maps plus output.

## Files in this folder

- `problem30.py` — Python solution
- `problem30.cpp` — C++ solution
