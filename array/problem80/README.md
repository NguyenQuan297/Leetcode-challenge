# 80. Remove Duplicates from Sorted Array II

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Given an integer array `nums` sorted in **non-decreasing** order, remove duplicates in-place such that each unique element appears at most **twice**.

Return the number of elements `k` after placing the final result in the first `k` slots of `nums`.

You must do this in-place with **O(1)** extra memory.

## Examples

**Example 1:**

- Input: `nums = [1,1,1,2,2,3]`
- Output: `5`, `nums = [1,1,2,2,3,_,_]`

**Example 2:**

- Input: `nums = [0,0,1,1,1,1,2,3,3]`
- Output: `7`, `nums = [0,0,1,1,2,3,3,_,_]`

## Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in non-decreasing order.

## Files in this folder

- `problem80.py` — Python solution
- `problem80.cpp` — C++ solution
