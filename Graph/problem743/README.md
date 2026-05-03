# 743. Network Delay Time

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

Given a directed weighted graph of `n` nodes (`1..n`) with edge list `times[i] = [u, v, w]`, send a signal from node `k`. Return the minimum time for **all** nodes to receive the signal, or `-1` if impossible.

## Examples

**Example 1:**

- Input: `times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2`
- Output: `2`

**Example 2:**

- Input: `times = [[1,2,1]], n = 2, k = 1`
- Output: `1`

**Example 3:**

- Input: `times = [[1,2,1]], n = 2, k = 2`
- Output: `-1`

## Constraints

- `1 <= k <= n <= 100`
- `1 <= times.length <= 6000`
- `0 <= wi <= 100`
- All pairs `(ui, vi)` are unique.

## Approach

**Dijkstra's algorithm** from source `k`:

- Use a min-heap with `(dist, node)`.
- Relax outgoing edges; once a node is popped it has its shortest distance.
- Answer is `max(dist.values())` if all `n` nodes reached, else `-1`.

Time complexity: **O((V + E) log V)**  
Space complexity: **O(V + E)**

## Files in this folder

- `problem743.py` — Python solution
- `problem743.cpp` — C++ solution
