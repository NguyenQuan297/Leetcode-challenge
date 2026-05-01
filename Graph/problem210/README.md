# 210. Course Schedule II

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

Same setup as [207. Course Schedule](../problem207/): `numCourses` courses labeled `0..numCourses-1` with `prerequisites[i] = [a, b]` meaning take `b` before `a`.

Return a valid **ordering** of all courses, or an **empty array** if impossible (cycle exists).

## Examples

**Example 1:**

- Input: `numCourses = 2, prerequisites = [[1,0]]`
- Output: `[0,1]`

**Example 2:**

- Input: `numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]`
- Output: `[0,2,1,3]` (any valid topological order)

**Example 3:**

- Input: `numCourses = 1, prerequisites = []`
- Output: `[0]`

## Constraints

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
- `ai != bi`, all pairs distinct.

## Approach

Same **Kahn's algorithm** as problem 207, extended to record the processing order:

1. Build adjacency list and in-degrees.
2. Enqueue all nodes with `in-degree == 0`.
3. Pop each node, append to `order`, decrement neighbors' in-degrees; enqueue those reaching `0`.
4. If `len(order) == numCourses`, return it; else return `[]`.

Time complexity: **O(V + E)**  
Space complexity: **O(V + E)**

## Files in this folder

- `problem210.py` — Python solution
- `problem210.cpp` — C++ solution
