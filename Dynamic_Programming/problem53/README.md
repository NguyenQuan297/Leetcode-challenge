# 53. Maximum Subarray

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given an integer array `nums`, find the contiguous subarray with the largest sum and return that sum.

## Examples

**Example 1:**

- Input: `nums = [-2,1,-3,4,-1,2,1,-5,4]`
- Output: `6`
- Explanation: `[4,-1,2,1]` has the largest sum `6`.

**Example 2:**

- Input: `nums = [1]`
- Output: `1`

**Example 3:**

- Input: `nums = [5,4,-1,7,8]`
- Output: `23`

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Approach

Use Kadane DP:

- `cur` = maximum subarray sum ending at current index
- `best` = maximum subarray sum seen so far

Transition for each `x`:

- `cur = max(x, cur + x)`
- `best = max(best, cur)`

This is equivalent to 1D DP where each state only depends on the previous one.

Time complexity: **O(n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem53.py` — Python solution
- `problem53.cpp` — C++ solution
