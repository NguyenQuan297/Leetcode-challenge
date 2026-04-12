# 99. Recover Binary Search Tree

**Topic:** [Tree](../) · **Difficulty:** Medium

## Description

You are given the `root` of a BST where **exactly two** nodes were swapped by mistake. Recover the tree **without changing its structure** (only fix values).

## Examples

**Example 1:**

- Input: `root = [1,3,null,null,2]`
- Output: `[3,1,null,null,2]`

**Example 2:**

- Input: `root = [3,1,4,null,null,2]`
- Output: `[2,1,4,null,null,3]`

## Constraints

- The number of nodes is in the range `[2, 1000]`.
- `-2^31 <= Node.val <= 2^31 - 1`

## Follow-up

An **O(n)** space solution (store inorder list or use an explicit stack) is straightforward. This folder uses **Morris traversal** for **O(1)** extra space: simulate inorder without stack by temporarily threading predecessors, find the two out-of-order pairs, then swap their `val`.

## Files in this folder

- `problem99.py` — Python solution
- `problem99.cpp` — C++ solution (`TreeNode` only with `-DLOCAL_JUDGE`)
