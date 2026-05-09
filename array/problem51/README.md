# 51. N-Queens

**Topic:** [Array](../) · **Difficulty:** Hard

## Description

Place `n` queens on an `n x n` chessboard so that no two queens attack each other. Return all distinct board configurations. `'Q'` = queen, `'.'` = empty.

## Examples

**Example 1:**

- Input: `n = 4`
- Output: `[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]`

**Example 2:**

- Input: `n = 1`
- Output: `[["Q"]]`

## Constraints

- `1 <= n <= 9`

## Approach

**Backtracking row-by-row** with three O(1) conflict sets:

- `cols` — columns already occupied
- `diag1` — occupied diagonals `(row - col)`
- `diag2` — occupied anti-diagonals `(row + col)`

Place one queen per row. For each column in the current row, skip if any set already contains the corresponding key. Otherwise place the queen, update the sets, recurse to the next row, then undo.

Time complexity: **O(n!)** — at most n! placements explored  
Space complexity: **O(n)** — recursion depth + sets

## Files in this folder

- `problem51.py` — Python solution
- `problem51.cpp` — C++ solution
