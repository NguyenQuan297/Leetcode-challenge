# 133. Clone Graph

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

Given a reference to a node in a **connected undirected graph**, return a **deep copy** (clone) of the graph.

Each node contains an integer `val` and a list of its `neighbors`.

## Examples

**Example 1:**

- Input: `adjList = [[2,4],[1,3],[2,4],[1,3]]`
- Output: `[[2,4],[1,3],[2,4],[1,3]]`

**Example 2:**

- Input: `adjList = [[]]`
- Output: `[[]]`

**Example 3:**

- Input: `adjList = []`
- Output: `[]`

## Constraints

- Number of nodes: `[0, 100]`
- `1 <= Node.val <= 100`
- `Node.val` is unique for each node.
- No repeated edges, no self-loops.
- The graph is connected.

## Approach

Use **DFS with a hash map** (`visited`) mapping original nodes to their clones:

- If `node` is `None`, return `None`.
- If `node` is already in `visited`, return the clone immediately (handles cycles).
- Otherwise: create a new node, store it in `visited`, then recursively clone all neighbors.

Time complexity: **O(V + E)**  
Space complexity: **O(V)** for the visited map and recursion stack

## Files in this folder

- `problem133.py` — Python solution
- `problem133.cpp` — C++ solution
