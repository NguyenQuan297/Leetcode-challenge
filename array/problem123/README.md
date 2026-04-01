# 123. Best Time to Buy and Sell Stock III

**Topic:** [Array](../) · **Difficulty:** Hard

## Description

You are given an array `prices` where `prices[i]` is the stock price on day `i`.

Return the maximum profit you can achieve if you may complete **at most two transactions**.

You must sell before you buy again (no overlapping transactions).

## Examples

**Example 1:**

- Input: `prices = [3,3,5,0,0,3,1,4]`
- Output: `6`
- Explanation: Buy at `0`, sell at `3` (profit `3`), then buy at `1`, sell at `4` (profit `3`). Total `6`.

**Example 2:**

- Input: `prices = [1,2,3,4,5]`
- Output: `4`

**Example 3:**

- Input: `prices = [7,6,4,3,1]`
- Output: `0`

## Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`

## Files in this folder

- `problem123.py` — Python solution
- `problem123.cpp` — C++ solution
