# 27. Remove Element

**Topic:** [Array](../) · **Difficulty:** Easy

## Description

Given an integer array `nums` and an integer `val`, **remove all occurrences of `val` in `nums` in-place**. The order of the elements may be changed. Then return the number of elements in `nums` which are **not** equal to `val`.

Consider the number of elements in `nums` which are not equal to `val` to be `k`. To get accepted you need to:

- Change `nums` so that the **first `k` elements** contain the elements which are not equal to `val`. The remaining elements are not important.
- **Return `k`.**

### Custom judge

The judge compares `k` to the expected length and, after sorting the first `k` elements of `nums`, checks equality with the expected multiset of kept values.

## Examples

**Example 1:**

- Input: `nums = [3,2,2,3]`, `val = 3`
- Output: `2`, `nums = [2,2,_,_]`
- Explanation: Return `k = 2`; the first two elements are `2`. Values after index `k - 1` are ignored.

**Example 2:**

- Input: `nums = [0,1,2,2,3,0,4,2]`, `val = 2`
- Output: `5`, `nums = [0,1,4,0,3,_,_,_]` (order of the first five may vary)
- Explanation: Return `k = 5`; the first five positions contain `0, 0, 1, 3, 4` in some order.

## Constraints

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

## Files in this folder

- `problem27.py` — Python solution
- `problem27.cpp` — C++ solution
