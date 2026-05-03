# 785. Is Graph Bipartite?

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

Given an undirected graph represented as an adjacency list `graph`, return `true` if the graph is **bipartite**.

A graph is bipartite if nodes can be split into two independent sets `A` and `B` such that every edge connects a node in `A` to a node in `B`.

## Examples

**Example 1:**

- Input: `graph = [[1,2,3],[0,2],[0,1,3],[0,2]]`
- Output: `false`

**Example 2:**

- Input: `graph = [[1,3],[0,2],[1,3],[0,2]]`
- Output: `true`
- Explanation: Sets `{0, 2}` and `{1, 3}`.

## Constraints

- `1 <= n <= 100`
- `0 <= graph[u].length < n`
- No self-edges, no parallel edges, undirected.

## Approach

**BFS 2-coloring**: try to color the graph with 2 colors so no two adjacent nodes share the same color.

- For each unvisited node, assign color `0` and BFS.
- For each neighbor: if uncolored → assign opposite color; if same color as current node → **not bipartite**.
- Handle disconnected components by iterating over all nodes.

Time complexity: **O(V + E)**  
Space complexity: **O(V)**

## Files in this folder

- `problem785.py` — Python solution
- `problem785.cpp` — C++ solution
