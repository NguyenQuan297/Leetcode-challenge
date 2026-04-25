# 45. Jump Game II

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given an array `nums` where `nums[i]` is the maximum jump length from index `i`, return the minimum number of jumps needed to reach the last index.

You are guaranteed that the last index is reachable.

## Examples

**Example 1:**

- Input: `nums = [2,3,1,1,4]`
- Output: `2`
- Explanation: Jump from index `0` to `1`, then from `1` to the last index.

**Example 2:**

- Input: `nums = [2,3,0,1,4]`
- Output: `2`

## Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- `nums[n - 1]` is reachable.

## Approach

Use a **greedy layer expansion** (equivalent to BFS on indices):

- `current_end` = rightmost index reachable with current number of jumps
- `farthest` = farthest index we can reach while scanning current layer
- Scan indices from left to right (up to `n - 2`):
  - update `farthest = max(farthest, i + nums[i])`
  - when `i == current_end`, we finish one layer, so:
    - `jumps += 1`
    - `current_end = farthest`

Because each jump count corresponds to one contiguous reachable range, this yields the minimum jumps.

Time complexity: **O(n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem45.py` — Python solution
- `problem45.cpp` — C++ solution
