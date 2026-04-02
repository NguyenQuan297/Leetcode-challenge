# 324. Wiggle Sort II

**Topic:** [Sorting](../) · **Difficulty:** Medium

## Description

Given an integer array `nums`, **reorder** it such that `nums[0] < nums[1] > nums[2] < nums[3]...`.

You may assume the input array always has a valid answer.

## Examples

**Example 1:**

- Input: `nums = [1,5,1,1,6,4]`
- Output: One valid order is `[1,6,1,5,1,4]` (other valid permutations exist).

**Example 2:**

- Input: `nums = [1,3,2,2,3,1]`
- Output: One valid order is `[2,3,1,3,1,2]`.

## Constraints

- `1 <= nums.length <= 5 * 10^4`
- `0 <= nums[i] <= 5000`
- It is guaranteed that a valid answer exists.

## Follow-up

`O(n)` time and/or in-place with `O(1)` extra space is possible (e.g. median + virtual indexing), but is more involved. This folder uses an `O(n log n)` sort-based construction with `O(n)` auxiliary space.

## Files in this folder

- `problem324.py` — Python solution
- `problem324.cpp` — C++ solution
