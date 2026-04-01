# 122. Best Time to Buy and Sell Stock II

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

You are given an integer array `prices` where `prices[i]` is the stock price on day `i`.

On each day, you may decide to buy and/or sell the stock. You can hold at most one share at any time, but you may complete multiple transactions (sell then buy again).

Return the maximum profit you can achieve.

## Examples

**Example 1:**

- Input: `prices = [7,1,5,3,6,4]`
- Output: `7`
- Explanation: Buy at `1`, sell at `5` (profit `4`), then buy at `3`, sell at `6` (profit `3`). Total `7`.

**Example 2:**

- Input: `prices = [1,2,3,4,5]`
- Output: `4`

**Example 3:**

- Input: `prices = [7,6,4,3,1]`
- Output: `0`

## Constraints

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

## Files in this folder

- `problem122.py` — Python solution
- `problem122.cpp` — C++ solution
