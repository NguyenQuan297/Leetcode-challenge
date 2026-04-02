# 75. Sort Colors

**Topic:** [Sorting](../) · **Difficulty:** Medium

## Description

Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order **red, white, and blue**.

Use integers `0`, `1`, and `2` to represent red, white, and blue respectively.

You must **not** use the library's sort function.

## Examples

**Example 1:**

- Input: `nums = [2,0,2,1,1,0]`
- Output: `[0,0,1,1,2,2]`

**Example 2:**

- Input: `nums = [2,0,1]`
- Output: `[0,1,2]`

## Constraints

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is `0`, `1`, or `2`.

## Follow-up

One-pass algorithm using only constant extra space (Dutch National Flag).

## Files in this folder

- `problem75.py` — Python solution
- `problem75.cpp` — C++ solution
