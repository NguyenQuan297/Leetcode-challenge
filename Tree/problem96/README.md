# 96. Unique Binary Search Trees

**Topic:** [Tree](../) · **Difficulty:** Medium

## Description

Given an integer `n`, return the number of structurally unique **BSTs** (binary search trees) that have exactly `n` nodes with unique values from `1` to `n`.

## Examples

**Example 1:**

- Input: `n = 3`
- Output: `5`

**Example 2:**

- Input: `n = 1`
- Output: `1`

## Constraints

- `1 <= n <= 19`

## Approach

Dynamic programming: let `dp[i]` be the count for `i` nodes. For root value `j` (`1 <= j <= i`), the left subtree has `j - 1` nodes and the right has `i - j`, so add `dp[j - 1] * dp[i - j]`. Base case `dp[0] = 1` (empty tree). This is the **Catalan** recurrence; values for `n <= 19` fit in 32-bit `int`.

## Related

- [95. Unique Binary Search Trees II](../problem95/) — enumerate all trees (same combinatorics, harder).

## Files in this folder

- `problem96.py` — Python solution
- `problem96.cpp` — C++ solution
