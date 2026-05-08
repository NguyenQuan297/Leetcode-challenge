# 39. Combination Sum

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Given an array of **distinct** integers `candidates` and a `target`, return all unique combinations that sum to `target`. The same number may be used **unlimited** times.

## Examples

**Example 1:**

- Input: `candidates = [2,3,6,7], target = 7`
- Output: `[[2,2,3],[7]]`

**Example 2:**

- Input: `candidates = [2,3,5], target = 8`
- Output: `[[2,2,2,2],[2,3,3],[3,5]]`

**Example 3:**

- Input: `candidates = [2], target = 1`
- Output: `[]`

## Constraints

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`, all distinct
- `1 <= target <= 40`

## Approach

**Backtracking with a start index** to avoid duplicate combinations:

- Sort `candidates` (allows early termination when `candidate > remaining`).
- At each step, try every candidate from index `start` onwards.
- If we pick `c`, recurse with `remaining - c` and the **same** `start` index (reuse allowed).
- When `remaining == 0`, record the current combination.
- Skip candidates larger than `remaining` (pruning).

Time complexity: **O(n^(T/M))** where `T = target`, `M = min(candidates)`  
Space complexity: **O(T/M)** recursion depth

## Files in this folder

- `problem39.py` — Python solution
- `problem39.cpp` — C++ solution
