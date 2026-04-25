# 55. Jump Game

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given an integer array `nums`, each element represents your maximum jump length from that position.

Return `true` if you can reach the last index, otherwise return `false`.

## Examples

**Example 1:**

- Input: `nums = [2,3,1,1,4]`
- Output: `true`

**Example 2:**

- Input: `nums = [3,2,1,0,4]`
- Output: `false`

## Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^5`

## Approach

Track the farthest reachable index while scanning left to right:

- `farthest = max(farthest, i + nums[i])`
- If at any position `i > farthest`, that position is unreachable, so return `false`.
- If `farthest` reaches or passes the last index, return `true`.

This can be viewed as DP with compressed state (only the best reachable frontier is needed).

Time complexity: **O(n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem55.py` — Python solution
- `problem55.cpp` — C++ solution
