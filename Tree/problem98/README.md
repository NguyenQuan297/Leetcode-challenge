# 98. Validate Binary Search Tree

**Topic:** [Tree](../) · **Difficulty:** Medium

## Description

Given the `root` of a binary tree, determine if it is a valid **BST**.

A valid BST is defined as:

- The left subtree of a node contains only nodes with keys **strictly less** than the node’s key.
- The right subtree contains only nodes with keys **strictly greater** than the node’s key.
- Both subtrees must also be binary search trees.

## Examples

**Example 1:**

- Input: `root = [2,1,3]`
- Output: `true`

**Example 2:**

- Input: `root = [5,1,4,null,null,3,6]`
- Output: `false` (value `3` lies in the right subtree of `5` but is not greater than `5`)

## Constraints

- The number of nodes is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

## Approach

**Iterative inorder:** a valid BST’s inorder traversal is **strictly increasing**. Walk left as far as possible with a stack, pop, compare to the previous value, then go right. **O(n)** time, **O(h)** stack space; avoids `std::function` overhead in C++ and deep recursion on tall skewed trees (`n` up to `10^4`).

Alternative: bounds DFS with `(lo, hi)` per node (also **O(n)**); the inorder version is often faster on LeetCode.

## Files in this folder

- `problem98.py` — Python solution
- `problem98.cpp` — C++ solution (`TreeNode` only with `-DLOCAL_JUDGE`)
