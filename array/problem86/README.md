# 86. Partition List

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Given the head of a linked list and a value `x`, partition the list so that:
- All nodes with `val < x` come before nodes with `val >= x`.
- The relative order within each partition is preserved.

## Examples

**Example 1:**

- Input: `head = [1,4,3,2,5,2], x = 3`
- Output: `[1,2,2,4,3,5]`

**Example 2:**

- Input: `head = [2,1], x = 2`
- Output: `[1,2]`

## Constraints

- `0 <= number of nodes <= 200`
- `-100 <= Node.val <= 100`
- `-200 <= x <= 200`

## Approach

Use **two dummy-headed lists**:

- `less_dummy` → collects nodes with `val < x`
- `greater_dummy` → collects nodes with `val >= x`

Traverse the original list once, appending each node to the appropriate tail. After the loop, link the tail of the `less` list to the head of the `greater` list and set `greater_tail.next = None` to terminate.

Time complexity: **O(n)**  
Space complexity: **O(1)** extra (relinks existing nodes)

## Files in this folder

- `problem86.py` — Python solution
- `problem86.cpp` — C++ solution
