# 101. Symmetric Tree

**Topic:** [Tree](../) · **Difficulty:** Easy

## Description

Given the `root` of a binary tree, check whether it is a **mirror of itself** (symmetric around its center).

## Examples

**Example 1:**

- Input: `root = [1,2,2,3,4,4,3]`
- Output: `true`

**Example 2:**

- Input: `root = [1,2,2,null,3,null,3]`
- Output: `false`

## Constraints

- The number of nodes is in the range `[1, 1000]`.
- `-100 <= Node.val <= 100`

## Approach

**Recursive:** Compare the left and right children of the root as mirror partners: `mirror(a, b)` requires `a.val == b.val`, `mirror(a.left, b.right)`, and `mirror(a.right, b.left)`.

**Follow-up (iterative):** Use a queue or deque of pairs `(a, b)`; pop, check values and push `(a.left, b.right)` and `(a.right, b.left)` when both children exist.

## Files in this folder

- `problem101.py` — Python solution (recursive)
- `problem101.cpp` — C++ solution (recursive; `TreeNode` only with `-DLOCAL_JUDGE`)
