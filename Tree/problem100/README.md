# 100. Same Tree

**Topic:** [Tree](../) · **Difficulty:** Easy

## Description

Given the roots of two binary trees `p` and `q`, return `true` if they are the **same** tree: structurally identical and matching values at every position.

## Examples

**Example 1:**

- Input: `p = [1,2,3]`, `q = [1,2,3]`
- Output: `true`

**Example 2:**

- Input: `p = [1,2]`, `q = [1,null,2]`
- Output: `false`

**Example 3:**

- Input: `p = [1,2,1]`, `q = [1,1,2]`
- Output: `false`

## Constraints

- The number of nodes in each tree is in the range `[0, 100]`.
- `-10^4 <= Node.val <= 10^4`

## Approach

Recursive DFS: both `null` → `true`; exactly one `null` → `false`; values differ → `false`; otherwise compare left subtrees and right subtrees.

## Files in this folder

- `problem100.py` — Python solution
- `problem100.cpp` — C++ solution (`TreeNode` only with `-DLOCAL_JUDGE`)
