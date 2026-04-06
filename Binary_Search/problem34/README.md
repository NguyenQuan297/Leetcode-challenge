# 34. Find First and Last Position of Element in Sorted Array

**Topic:** [Binary Search](../) · **Difficulty:** Medium

## Description

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with **O(log n)** runtime complexity.

## Examples

**Example 1:**

- Input: `nums = [5,7,7,8,8,10]`, `target = 8`
- Output: `[3,4]`

**Example 2:**

- Input: `nums = [5,7,7,8,8,10]`, `target = 6`
- Output: `[-1,-1]`

**Example 3:**

- Input: `nums = []`, `target = 0`
- Output: `[-1,-1]`

## Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `nums` is sorted in non-decreasing order
- `-10^9 <= target <= 10^9`

## Approach

Two binary searches on the sorted array: one for the **leftmost** index where `nums[i] >= target` (then verify `nums[i] == target`), and one for the **rightmost** index where `nums[i] <= target` (after the target is known to exist).

## Files in this folder

- `problem34.py` — Python solution
- `problem34.cpp` — C++ solution
