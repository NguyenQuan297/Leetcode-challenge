# 268. Missing Number

**Topic:** [Sorting](../) · **Difficulty:** Easy

## Description

Given an array `nums` containing `n` **distinct** numbers in the range `[0, n]`, return the only number in the range that is **missing** from the array.

## Examples

**Example 1:**

- Input: `nums = [3,0,1]`
- Output: `2`

**Example 2:**

- Input: `nums = [0,1]`
- Output: `2`

**Example 3:**

- Input: `nums = [9,6,4,2,3,5,7,0,1]`
- Output: `8`

## Constraints

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All numbers in `nums` are unique.

## Follow-up

`O(n)` time and `O(1)` extra space (XOR of indices `0..n-1`, values, and `n`).

## Files in this folder

- `problem268.py` — Python solution
- `problem268.cpp` — C++ solution
