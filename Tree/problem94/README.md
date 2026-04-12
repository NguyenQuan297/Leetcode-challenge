# 94. Binary Tree Inorder Traversal

**Topic:** [Tree](../) · **Difficulty:** Easy

## Description

Given the `root` of a binary tree, return the **inorder** traversal of its nodes' values (left subtree, then node, then right subtree).

## Examples

**Example 1:**

- Input: `root = [1,null,2,3]` (tree: `1` — right — `2` — left — `3`)
- Output: `[1,3,2]`

**Example 2:**

- Input: `root = [1,2,3,4,5,null,8,null,null,6,7,9]`
- Output: `[4,2,6,5,7,1,3,9,8]`

**Example 3:**

- Input: `root = []`
- Output: `[]`

**Example 4:**

- Input: `root = [1]`
- Output: `[1]`

## Constraints

- The number of nodes is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Follow-up

A recursive solution is straightforward. This folder uses an **iterative** inorder traversal with an explicit **stack**: walk left as far as possible while pushing nodes, then pop, record the value, and continue from the right child.

## Files in this folder

- `problem94.py` — Python solution (iterative)
- `problem94.cpp` — C++ solution (iterative). `TreeNode` is only defined when compiling with `-DLOCAL_JUDGE` (so LeetCode’s own `TreeNode` is not redefined). For the IDE: root `.clangd` adds `-DLOCAL_JUDGE` for `Tree/**/*.cpp`; `.vscode/c_cpp_properties.json` defines `LOCAL_JUDGE` for IntelliSense. Local check: `g++ -std=c++17 -DLOCAL_JUDGE -c problem94.cpp`.
