# 90. Subsets II

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets.

## Examples

**Example 1:**

- Input: `nums = [1,2,2]`
- Output: `[[],[1],[1,2],[1,2,2],[2],[2,2]]`

**Example 2:**

- Input: `nums = [0]`
- Output: `[[],[0]]`

## Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

## Approach

**Backtracking with duplicate skipping** after sorting:

1. Sort `nums` so duplicates are adjacent.
2. At each backtracking call, iterate from `start` to the end:
   - Skip `nums[i]` if `i > start` and `nums[i] == nums[i-1]` (would create a duplicate subset at this depth).
   - Otherwise include `nums[i]`, recurse with `i + 1`, then remove it.
3. Record the current path at every call (including the empty path at the root).

Time complexity: **O(2^n)** — each element is either included or skipped  
Space complexity: **O(n)** recursion depth

## Files in this folder

- `problem90.py` — Python solution
- `problem90.cpp` — C++ solution
