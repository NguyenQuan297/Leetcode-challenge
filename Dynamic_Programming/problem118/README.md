# 118. Pascal's Triangle

**Topic:** [Dynamic Programming](../) · **Difficulty:** Easy

## Description

Given an integer `numRows`, return the first `numRows` of Pascal's triangle.

Each number is the sum of the two numbers directly above it.

## Examples

**Example 1:**

- Input: `numRows = 5`
- Output: `[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]`

**Example 2:**

- Input: `numRows = 1`
- Output: `[[1]]`

## Constraints

- `1 <= numRows <= 30`

## Approach

Build each row from the previous one:

- Every row starts and ends with `1`.
- Inner element `j`: `row[j] = prev[j-1] + prev[j]`

Time complexity: **O(numRows²)**  
Space complexity: **O(numRows²)** for the output

## Files in this folder

- `problem118.py` — Python solution
- `problem118.cpp` — C++ solution
