# 104. Maximum Depth of Binary Tree

**Topic:** [Tree](../) · **Difficulty:** Easy

## Description

Given the `root` of a binary tree, return its **maximum depth** — the number of nodes along the longest path from the root down to the farthest leaf.

## Examples

**Example 1:**

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `3`

**Example 2:**

- Input: `root = [1,null,2]`
- Output: `2`

## Constraints

- The number of nodes is in the range `[0, 10^4]`.
- `-100 <= Node.val <= 100`

## Approach

**Recursive:** empty tree depth `0`; otherwise `1 + max(depth(left), depth(right))`.

For a **very deep skewed** tree in Python, an **iterative BFS** (level count) avoids hitting the recursion limit.

## Files in this folder

- `problem104.py` — Python solution
- `problem104.cpp` — C++ solution (`TreeNode` only with `-DLOCAL_JUDGE`)
