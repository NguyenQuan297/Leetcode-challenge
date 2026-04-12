# 102. Binary Tree Level Order Traversal

**Topic:** [Tree](../) · **Difficulty:** Medium

## Description

Given the `root` of a binary tree, return the **level order** traversal of its nodes' values (left to right, level by level).

## Examples

**Example 1:**

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `[[3],[9,20],[15,7]]`

**Example 2:**

- Input: `root = [1]`
- Output: `[[1]]`

**Example 3:**

- Input: `root = []`
- Output: `[]`

## Constraints

- The number of nodes is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`

## Approach

**BFS:** use a queue; each iteration drains the current size of the queue as one level, appending children for the next level.

## Files in this folder

- `problem102.py` — Python solution
- `problem102.cpp` — C++ solution (`TreeNode` only with `-DLOCAL_JUDGE`)
