# 103. Binary Tree Zigzag Level Order Traversal

**Topic:** [Tree](../) · **Difficulty:** Medium

## Description

Given the `root` of a binary tree, return the **zigzag level order** traversal of its values: left-to-right on level 0, right-to-left on level 1, then alternate.

## Examples

**Example 1:**

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `[[3],[20,9],[15,7]]`

**Example 2:**

- Input: `root = [1]`
- Output: `[[1]]`

**Example 3:**

- Input: `root = []`
- Output: `[]`

## Constraints

- The number of nodes is in the range `[0, 2000]`.
- `-100 <= Node.val <= 100`

## Approach

Same **BFS by level** as [102](../problem102/); after building each level list, **reverse** when the depth index is odd (`1, 3, 5, ...`).

## Files in this folder

- `problem103.py` — Python solution
- `problem103.cpp` — C++ solution (`TreeNode` only with `-DLOCAL_JUDGE`)
