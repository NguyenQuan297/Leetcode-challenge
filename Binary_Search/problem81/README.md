# 81. Search in Rotated Sorted Array II

**Topic:** [Binary Search](../) · **Difficulty:** Medium

## Description

There is an integer array `nums` sorted in non-decreasing order (values are **not** necessarily distinct).

Before being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (`0 <= k < nums.length`) so that the resulting array is  
`[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed).

Given the array `nums` **after** the rotation and an integer `target`, return `true` if `target` is in `nums`, or `false` if it is not.

You must decrease the overall operation steps as much as possible.

## Examples

**Example 1:**

- Input: `nums = [2,5,6,0,0,1,2]`, `target = 0`
- Output: `true`

**Example 2:**

- Input: `nums = [2,5,6,0,0,1,2]`, `target = 3`
- Output: `false`

## Constraints

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is guaranteed to be rotated at some pivot
- `-10^4 <= target <= 10^4`

## Approach

Same idea as “search in rotated sorted array”: at each mid, one side is normally sorted so you can decide whether `target` lies in that range. With **duplicates**, when `nums[lo] == nums[mid]` you cannot tell which side is the sorted half, so you only know you can drop `nums[lo]` and do `lo++`. That extra step can happen many times.

## Follow-up: duplicates and runtime

**Yes, duplicates can change the worst-case complexity.**

- **Without duplicates** (LeetCode 33), you can always tell which half is sorted, so each step cuts the search space about in half: **O(log n)**.
- **With duplicates**, if `nums[lo] == nums[mid]`, both sides might still contain the answer (e.g. many copies of the same value around the rotation). The safe fix is to move `lo` by one instead of halving the interval. In the worst case (e.g. almost all elements equal), you may remove only one element per step, so the cost becomes **O(n)** in the worst case, even though the **average** case can still behave like binary search.

## Files in this folder

- `problem81.py` — Python solution
- `problem81.cpp` — C++ solution
