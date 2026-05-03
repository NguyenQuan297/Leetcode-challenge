# 797. All Paths From Source to Target

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

Given a DAG of `n` nodes labeled `0` to `n-1`, return all possible paths from node `0` to node `n-1` in any order.

## Examples

**Example 1:**

- Input: `graph = [[1,2],[3],[3],[]]`
- Output: `[[0,1,3],[0,2,3]]`

**Example 2:**

- Input: `graph = [[4,3,1],[3,2,4],[3],[4],[]]`
- Output: `[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]`

## Constraints

- `2 <= n <= 15`
- No self-loops, guaranteed DAG.

## Approach

**DFS with backtracking** from node `0`:

- Maintain the current path.
- When reaching node `n-1`, record a copy of the path.
- Since the graph is a DAG (no cycles), no `visited` set is needed.

Time complexity: **O(2^n · n)** — exponential paths in worst case  
Space complexity: **O(2^n · n)** for the output

## Files in this folder

- `problem797.py` — Python solution
- `problem797.cpp` — C++ solution
