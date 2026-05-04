# 134. Gas Station

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

There are `n` gas stations on a circular route. `gas[i]` is the gas available at station `i`, and `cost[i]` is the gas needed to travel from station `i` to station `i+1`.

Return the starting station index if you can complete the circuit once clockwise, otherwise return `-1`. The answer is guaranteed to be unique.

## Examples

**Example 1:**

- Input: `gas = [1,2,3,4,5], cost = [3,4,5,1,2]`
- Output: `3`

**Example 2:**

- Input: `gas = [2,3,4], cost = [3,4,3]`
- Output: `-1`

## Constraints

- `n == gas.length == cost.length`
- `1 <= n <= 10^5`
- `0 <= gas[i], cost[i] <= 10^4`

## Approach

Use a **single-pass greedy**:

- If `sum(gas) < sum(cost)`, no solution exists → return `-1`.
- Otherwise, track `tank` (running surplus from current candidate start):
  - Add `gas[i] - cost[i]` at each station.
  - If `tank < 0`, the current candidate cannot reach station `i+1`:
    reset `tank = 0` and set the next candidate `start = i + 1`.
- The final `start` is guaranteed to be the answer because:
  - A solution exists (total surplus ≥ 0).
  - Any station before `start` was already proven unable to maintain a non-negative tank.

Time complexity: **O(n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem134.py` — Python solution
- `problem134.cpp` — C++ solution
