# 152. Maximum Product Subarray

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Given an integer array `nums`, find the contiguous subarray with the largest product and return that product.

## Examples

**Example 1:**

- Input: `nums = [2,3,-2,4]`
- Output: `6`
- Explanation: `[2,3]` has product `6`.

**Example 2:**

- Input: `nums = [-2,0,-1]`
- Output: `0`

## Constraints

- `1 <= nums.length <= 2 * 10^4`
- `-10 <= nums[i] <= 10`

## Approach

Track both the **running maximum** and **running minimum** ending at each index, because a negative minimum can become the new maximum when multiplied by a negative number.

At each element `x`:
- `cur_max = max(x, cur_max * x, cur_min * x)`
- `cur_min = min(x, prev_max * x, cur_min * x)`

Update the global `best = max(best, cur_max)`.

Time complexity: **O(n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem152.py` — Python solution
- `problem152.cpp` — C++ solution
