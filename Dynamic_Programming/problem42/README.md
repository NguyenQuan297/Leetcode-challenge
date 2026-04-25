# 42. Trapping Rain Water

**Topic:** [Dynamic Programming](../) · **Difficulty:** Hard

## Description

Given `n` non-negative integers `height` where each bar has width `1`, compute how much rain water can be trapped.

## Examples

**Example 1:**

- Input: `height = [0,1,0,2,1,0,1,3,2,1,2,1]`
- Output: `6`

**Example 2:**

- Input: `height = [4,2,0,3,2,5]`
- Output: `9`

## Constraints

- `n == height.length`
- `1 <= n <= 2 * 10^4`
- `0 <= height[i] <= 10^5`

## Approach

Use prefix/suffix DP arrays:

- `left_max[i]`: highest bar from left up to `i`
- `right_max[i]`: highest bar from right up to `i`

Water at index `i` is:

- `min(left_max[i], right_max[i]) - height[i]`

If positive, add to answer.

This precomputes the two boundaries for each position, then sums trapped water in one pass.

Time complexity: **O(n)**  
Space complexity: **O(n)**

## Files in this folder

- `problem42.py` — Python solution
- `problem42.cpp` — C++ solution
