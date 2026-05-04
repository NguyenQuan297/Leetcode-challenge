# 135. Candy

**Topic:** [Array](../) · **Difficulty:** Hard

## Description

Give each of `n` children (with a `ratings` array) the minimum candies such that:

1. Every child gets at least `1` candy.
2. A child with a **higher** rating than a neighbor gets **more** candies than that neighbor.

Return the minimum total candies.

## Examples

**Example 1:**

- Input: `ratings = [1,0,2]`
- Output: `5`
- Explanation: `[2, 1, 2]`

**Example 2:**

- Input: `ratings = [1,2,2]`
- Output: `4`
- Explanation: `[1, 2, 1]`

## Constraints

- `1 <= n <= 2 * 10^4`
- `0 <= ratings[i] <= 2 * 10^4`

## Approach

Two-pass greedy on a `candies` array initialized to all `1`:

- **Left → Right pass:** if `ratings[i] > ratings[i-1]`, set `candies[i] = candies[i-1] + 1`.
- **Right → Left pass:** if `ratings[i] > ratings[i+1]`, set `candies[i] = max(candies[i], candies[i+1] + 1)`.

Each pass enforces one direction of the constraint. Both together guarantee the global minimum.

Time complexity: **O(n)**  
Space complexity: **O(n)**

## Files in this folder

- `problem135.py` — Python solution
- `problem135.cpp` — C++ solution
