# 162. Find Peak Element

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

A **peak element** is strictly greater than both its neighbors. Given `nums`, return the index of any peak element. Treat `nums[-1] = nums[n] = -∞`.

Must run in **O(log n)** time.

## Examples

**Example 1:**

- Input: `nums = [1,2,3,1]`
- Output: `2`

**Example 2:**

- Input: `nums = [1,2,1,3,5,6,4]`
- Output: `5` (or `1`)

## Constraints

- `1 <= nums.length <= 1000`
- `nums[i] != nums[i + 1]` for all valid `i`

## Approach

**Binary search on the slope:**

- If `nums[mid] < nums[mid + 1]`, the peak lies to the **right** → `lo = mid + 1`.
- Otherwise, the peak lies to the **left** (including `mid`) → `hi = mid`.
- When `lo == hi`, that index is a peak.

Correctness: we always converge toward a peak because we follow the uphill direction, and the boundary condition (`-∞` on both ends) guarantees a peak exists.

Time complexity: **O(log n)**  
Space complexity: **O(1)**

## Files in this folder

- `problem162.py` — Python solution
- `problem162.cpp` — C++ solution
