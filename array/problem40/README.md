# 40. Combination Sum II

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Given a collection of numbers `candidates` (may have duplicates) and a `target`, find all unique combinations where numbers sum to `target`. Each number may only be used **once**.

## Examples

**Example 1:**

- Input: `candidates = [10,1,2,7,6,1,5], target = 8`
- Output: `[[1,1,6],[1,2,5],[1,7],[2,6]]`

**Example 2:**

- Input: `candidates = [2,5,2,1,2], target = 5`
- Output: `[[1,2,2],[5]]`

## Constraints

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## Approach

Same backtracking as problem 39, with two key differences:

1. **Each element used at most once**: pass `i + 1` (not `i`) when recurring.
2. **Skip duplicates at the same depth**: after sorting, if `i > start` and `candidates[i] == candidates[i-1]`, skip to avoid duplicate combinations.

Time complexity: **O(2^n)** in the worst case  
Space complexity: **O(n)** recursion depth

## Files in this folder

- `problem40.py` — Python solution
- `problem40.cpp` — C++ solution
