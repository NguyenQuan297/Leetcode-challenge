# 154. Find Minimum in Rotated Sorted Array II

**Topic:** [Array](../) · **Difficulty:** Hard

## Description

Given a sorted array `nums` that was rotated some number of times and **may contain duplicates**, return the **minimum** element.

You should decrease the overall operation steps as much as possible.

## Examples

**Example 1:**

- Input: `nums = [1,3,5]`
- Output: `1`

**Example 2:**

- Input: `nums = [2,2,2,0,1]`
- Output: `0`

## Constraints

- `1 <= nums.length <= 5000`
- `-5000 <= nums[i] <= 5000`
- `nums` is sorted and rotated between 1 and n times.

## Notes

Because duplicates exist, the binary search can degrade to **O(n)** in the worst case (e.g. many equal boundary values).

## Files in this folder

- `problem154.py` — Python solution
- `problem154.cpp` — C++ solution
