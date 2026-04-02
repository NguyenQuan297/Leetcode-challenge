# 56. Merge Intervals

**Topic:** [Sorting](../) · **Difficulty:** Medium

## Description

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all **overlapping** intervals, and return an array of the **non-overlapping** intervals that cover all the intervals in the input.

## Examples

**Example 1:**

- Input: `intervals = [[1,3],[2,6],[8,10],[15,18]]`
- Output: `[[1,6],[8,10],[15,18]]`

**Example 2:**

- Input: `intervals = [[1,4],[4,5]]`
- Output: `[[1,5]]`

**Example 3:**

- Input: `intervals = [[4,7],[1,4]]`
- Output: `[[1,7]]`

## Constraints

- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 10^4`

## Files in this folder

- `problem56.py` — Python solution
- `problem56.cpp` — C++ solution
