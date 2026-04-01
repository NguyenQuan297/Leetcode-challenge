# 31. Next Permutation

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

A **permutation** of an array of integers is an arrangement of its members into a sequence or linear order.

The **next permutation** of an array is the next **lexicographically greater** permutation. If all permutations were sorted lexicographically, the next permutation is the one immediately after the current. If no larger rearrangement exists, rearrange to the **lowest** order (ascending sort).

Given an array `nums`, find the **next permutation** of `nums`.

The replacement must be **in place** and use only **constant extra memory**.

## Examples

**Example 1:**

- Input: `nums = [1,2,3]`
- Output: `nums = [1,3,2]`

**Example 2:**

- Input: `nums = [3,2,1]`
- Output: `nums = [1,2,3]` (wraps to smallest permutation)

**Example 3:**

- Input: `nums = [1,1,5]`
- Output: `nums = [1,5,1]`

## Constraints

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

## Files in this folder

- `problem31.py` — Python solution
- `problem31.cpp` — C++ solution
