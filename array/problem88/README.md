# 88. Merge Sorted Array

**Topic:** [Array](../) · **Difficulty:** Easy

## Description

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of valid elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should be stored inside `nums1` in-place. `nums1` has length `m + n`, where its last `n` slots are extra space.

## Examples

**Example 1:**

- Input: `nums1 = [1,2,3,0,0,0]`, `m = 3`, `nums2 = [2,5,6]`, `n = 3`
- Output: `[1,2,2,3,5,6]`

**Example 2:**

- Input: `nums1 = [1]`, `m = 1`, `nums2 = []`, `n = 0`
- Output: `[1]`

**Example 3:**

- Input: `nums1 = [0]`, `m = 0`, `nums2 = [1]`, `n = 1`
- Output: `[1]`

## Constraints

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-10^9 <= nums1[i], nums2[j] <= 10^9`

## Follow-up

Can you do it in `O(m + n)` time?

## Files in this folder

- `problem88.py` — Python solution
- `problem88.cpp` — C++ solution
