# 547. Number of Provinces

**Topic:** [Graph](../) · **Difficulty:** Medium

## Description

Given an `n x n` adjacency matrix `isConnected`, where `isConnected[i][j] == 1` means city `i` and city `j` are directly connected, return the total number of **provinces** (connected components).

## Examples

**Example 1:**

- Input: `isConnected = [[1,1,0],[1,1,0],[0,0,1]]`
- Output: `2`

**Example 2:**

- Input: `isConnected = [[1,0,0],[0,1,0],[0,0,1]]`
- Output: `3`

## Constraints

- `1 <= n <= 200`
- `isConnected[i][j]` is `0` or `1`
- `isConnected[i][i] == 1`
- `isConnected[i][j] == isConnected[j][i]`

## Approach

Use **Union-Find (Disjoint Set Union)**:

- Start with `n` components.
- For each edge `(i, j)` where `i < j` and `isConnected[i][j] == 1`, union the two sets; if they were in different sets, decrement the component count.

Path compression + union by rank keeps each operation nearly `O(1)`.

Time complexity: **O(n²·α(n))** ≈ O(n²)  
Space complexity: **O(n)**

## Files in this folder

- `problem547.py` — Python solution
- `problem547.cpp` — C++ solution
