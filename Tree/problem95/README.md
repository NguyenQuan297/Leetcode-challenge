# 95. Unique Binary Search Trees II

**Topic:** [Tree](../) · **Difficulty:** Medium

## Description

Given an integer `n`, return all the structurally unique **BSTs** (binary search trees) that have exactly `n` nodes with unique values from `1` to `n`. Return the answer in any order.

## Examples

**Example 1:**

- Input: `n = 3`
- Output: five distinct BST shapes (values `1..3`), e.g. level-order forms like `[1,null,2,null,3]`, `[2,1,3]`, etc.

**Example 2:**

- Input: `n = 1`
- Output: `[[1]]`

## Constraints

- `1 <= n <= 8`

## Approach

For each interval `[start, end]` of values, try every `i` as root: all left BSTs from `gen(start, i - 1)` pair with all right BSTs from `gen(i + 1, end)`. Combine with a new `TreeNode(i)`. If `start > end`, return `[None]` as the empty subtree choice.

**Speed:** Cache `gen(start, end)` in a memo (there are only `O(n^2)` distinct ranges for `n <= 8`). When attaching a cached left/right subtree to a new root, **clone** that subtree so different trees in the final list do not share the same node objects.

## Files in this folder

- `problem95.py` — Python solution
- `problem95.cpp` — C++ solution (`TreeNode` only with `-DLOCAL_JUDGE`, same as problem 94)
