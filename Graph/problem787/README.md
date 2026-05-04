# 787. Cheapest Flights Within K Stops

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

There are `n` cities. Given a list of directed flights `[from, to, price]`, return the cheapest price from `src` to `dst` with at most `k` stops. Return `-1` if no such route exists.

## Examples

**Example 1:**

- Input: `n=4, flights=[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src=0, dst=3, k=1`
- Output: `700`

**Example 2:**

- Input: `n=3, flights=[[0,1,100],[1,2,100],[0,2,500]], src=0, dst=2, k=1`
- Output: `200`

**Example 3:**

- Input: `n=3, flights=[[0,1,100],[1,2,100],[0,2,500]], src=0, dst=2, k=0`
- Output: `500`

## Constraints

- `2 <= n <= 100`
- `0 <= flights.length <= n*(n-1)/2`
- `1 <= price <= 10^4`
- `0 <= src, dst, k < n`, `src != dst`

## Approach

Use **BFS level-by-level** (each level = one more flight taken):

1. Build adjacency list from the flight list.
2. `dist[i]` = cheapest cost to reach city `i` found so far; initialize `dist[src] = 0`, rest `INF`.
3. Put `(src, 0)` into a queue.
4. Run exactly `k+1` BFS levels (= at most `k+1` edges = at most `k` intermediate stops):
   - Process only the nodes in the **current level** (snapshot the queue size).
   - For each neighbor, if the new cost is cheaper than `dist[neighbor]`, update and enqueue.
5. Return `dist[dst]` or `-1` if unreachable.

Snapshotting the queue size at the start of each level ensures we never use more than `k+1` edges in a single path.

Time complexity: **O(k · E)**  
Space complexity: **O(n + E)** for the adjacency list and queue

## Files in this folder

- `problem787.py` — Python solution
- `problem787.cpp` — C++ solution
