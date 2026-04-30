# 207. Course Schedule

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

There are `numCourses` courses labeled `0` to `numCourses - 1`. Given `prerequisites[i] = [a, b]` meaning you must take course `b` before `a`, return `true` if you can finish all courses, otherwise `false`.

This is equivalent to: **does the directed graph contain a cycle?**

## Examples

**Example 1:**

- Input: `numCourses = 2, prerequisites = [[1,0]]`
- Output: `true`

**Example 2:**

- Input: `numCourses = 2, prerequisites = [[1,0],[0,1]]`
- Output: `false`

## Constraints

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- All pairs are unique.

## Approach

**Topological sort via Kahn's algorithm (BFS + in-degree):**

1. Build adjacency list and compute in-degree for every node.
2. Push all nodes with `in-degree == 0` into a queue.
3. Process each node: decrement in-degree of its neighbors; enqueue any that reach `0`.
4. If total processed nodes == `numCourses`, no cycle exists → return `true`.

Time complexity: **O(V + E)**  
Space complexity: **O(V + E)**

## Files in this folder

- `problem207.py` — Python solution
- `problem207.cpp` — C++ solution
