# 399. Evaluate Division

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

Given `equations[i] = [A, B]` and `values[i]` such that `A / B = values[i]`, answer queries `C / D`.

Return `-1.0` if the answer cannot be determined (unknown variable or unreachable node).

## Examples

**Example 1:**

- Input: `equations = [["a","b"],["b","c"]], values = [2.0,3.0]`
- Queries: `[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]`
- Output: `[6.0, 0.5, -1.0, 1.0, -1.0]`

**Example 2:**

- Input: `equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0]`
- Queries: `[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]`
- Output: `[3.75, 0.4, 5.0, 0.2]`

## Constraints

- `1 <= equations.length <= 20`
- `0.0 < values[i] <= 20.0`
- `1 <= queries.length <= 20`

## Approach

Model as a **weighted directed graph**:

- `A / B = v` → edge `A → B` with weight `v`, edge `B → A` with weight `1/v`.

For each query `(C, D)`:

- If either node is unknown → `-1.0`
- If `C == D` → `1.0`
- Run **BFS** from `C`, propagating the product of edge weights, until reaching `D` or exhausting reachable nodes.

Time complexity: **O((E + Q) · V)** where E = equations, Q = queries, V = variables  
Space complexity: **O(V + E)**

## Files in this folder

- `problem399.py` — Python solution
- `problem399.cpp` — C++ solution
