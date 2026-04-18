# 41. First Missing Positive

**Topic:** [Hash Table](../) · **Difficulty:** Hard

## Description

Given an unsorted integer array `nums`, return the **smallest positive integer** that does not appear in `nums`.

You must use **O(n)** time and **O(1)** auxiliary space (besides the input array).

## Examples

**Example 1:**

- Input: `nums = [1,2,0]`
- Output: `3`

**Example 2:**

- Input: `nums = [3,4,-1,1]`
- Output: `2`

**Example 3:**

- Input: `nums = [7,8,9,11,12]`
- Output: `1`

## Constraints

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

## Approach

Use indices `0..n-1` as an **implicit hash table** (direct addressing): index `k` represents whether positive integer `k + 1` has been seen.

**C++ (`problem41.cpp`)** and **Python (`problem41.py`):** same **cyclic swap** — for each index `i`, keep swapping `nums[i]` with `nums[nums[i]-1]` while `nums[i]` lies in `[1, n]` and is not already at its home cell (`nums[x-1] != x` stops duplicates).

**Python:** inner loop `while (x := nums[i]) >= 1 and x <= n and nums[x - 1] != x:` — one read of `nums[i]` per iteration, then swap into place; `and` short-circuits so `nums[x - 1]` is not evaluated when `x` is outside `[1, n]`. Second pass: first index with `nums[i] != i + 1`, else `n + 1`.

## Files in this folder

- `problem41.py` — Python solution
- `problem41.cpp` — C++ solution
