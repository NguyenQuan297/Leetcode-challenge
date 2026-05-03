# 684. Redundant Connection

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

A tree of `n` nodes has one extra edge added. Given `edges[i] = [a, b]` forming an undirected graph, return the **last edge** that can be removed to restore a tree.

## Examples

**Example 1:**

- Input: `edges = [[1,2],[1,3],[2,3]]`
- Output: `[2,3]`

**Example 2:**

- Input: `edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]`
- Output: `[1,4]`

## Constraints

- `3 <= n <= 1000`
- `n == edges.length`
- `1 <= ai < bi <= n`
- No repeated edges, graph is connected.

## Approach

Process edges one by one with **Union-Find**:

- For each edge `(u, v)`, try to union the two nodes.
- If they are **already in the same component** (same root), this edge forms a cycle → it is the redundant edge → return it.
- Otherwise union them and continue.

Since we process left to right and return the **first** edge that creates a cycle, which is also the **last** such edge if there is only one extra edge (problem guarantees exactly one).

Time complexity: **O(n·α(n))** ≈ O(n)  
Space complexity: **O(n)**

## Files in this folder

- `problem684.py` — Python solution
- `problem684.cpp` — C++ solution
