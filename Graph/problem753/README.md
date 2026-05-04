# 753. Cracking the Safe

**Topic:** [Graph](../) · **Difficulty:** Hard

## Description

A safe has a password of `n` digits, each in `[0, k-1]`. Return any **shortest string** that is guaranteed to contain every possible n-digit password as a substring.

## Examples

**Example 1:**

- Input: `n = 1, k = 2`
- Output: `"01"` (or `"10"`)

**Example 2:**

- Input: `n = 2, k = 2`
- Output: `"01100"` (or any valid De Bruijn sequence)

## Constraints

- `1 <= n <= 4`
- `1 <= k <= 10`
- `1 <= k^n <= 4096`

## Approach

Build the **De Bruijn sequence** via an **Eulerian circuit** on the De Bruijn graph:

- **Node**: an `(n-1)`-digit string (a "state" = last n-1 chars typed).
- **Edge**: from node `s`, appending digit `d` creates edge `s+d`, moving to node `s[1:]+d`.
- Every `n`-digit password corresponds to exactly one edge. We need to traverse **all** `k^n` edges once.

Since each node has exactly `k` in-edges and `k` out-edges, the graph is Eulerian.

Use **post-order DFS** (Hierholzer's idea):
- Greedily follow unused edges (DFS).
- On backtrack, append the digit used to the result.
- Reverse at the end and prepend the starting `(n-1)` prefix.

Result length: `k^n + (n - 1)`.

Time complexity: **O(k^n)**  
Space complexity: **O(k^n)**

## Files in this folder

- `problem753.py` — Python solution
- `problem753.cpp` — C++ solution
