# 26. Remove Duplicates from Sorted Array

**Topic:** [Array](../) · **Difficulty:** Easy

## Description

Given an integer array `nums` sorted in **non-decreasing** order, **remove the duplicates in-place** such that each unique element appears only **once**. The relative order of the elements should be kept the same.

Consider the number of unique elements in `nums` to be `k`. After removing duplicates, **return** `k`.

The **first `k` elements** of `nums` should contain the unique numbers in sorted order. The remaining elements beyond index `k - 1` can be ignored.

### Custom judge

The judge checks that `k` matches the expected length and that `nums[0..k-1]` equals the expected unique prefix.

## Examples

**Example 1:**

- Input: `nums = [1,1,2]`
- Output: `2`, `nums = [1,2,_]`
- Explanation: Return `k = 2`, with the first two elements of `nums` being `1` and `2`. Values after index `k - 1` are ignored.

**Example 2:**

- Input: `nums = [0,0,1,1,1,2,2,3,3,4]`
- Output: `5`, `nums = [0,1,2,3,4,_,_,_,_,_]`
- Explanation: Return `k = 5`; the first five elements are `0, 1, 2, 3, 4`.

## Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is sorted in non-decreasing order.

## Files in this folder

- `problem26.py` — Python solution
- `problem26.cpp` — C++ solution
