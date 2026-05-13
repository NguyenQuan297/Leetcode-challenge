# 84. Largest Rectangle in Histogram

**Topic:** [Array](../) · **Difficulty:** Hard

## Description

Given an array `heights` where `heights[i]` is the height of the `i`-th bar (width = 1), return the area of the largest rectangle in the histogram.

## Examples

**Example 1:**

- Input: `heights = [2,1,5,6,2,3]`
- Output: `10`

**Example 2:**

- Input: `heights = [2,4]`
- Output: `4`

## Constraints

- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`

## Approach

**Monotonic increasing stack** with an inline sentinel — no extra list allocation:

- Iterate `i` from `0` to `n` (inclusive). At `i == n`, treat height as `0` (sentinel) to flush all remaining stack entries without modifying the input array.
- Maintain a stack of **indices** in increasing height order.
- When `heights[i] < heights[stack.top()]`, pop and calculate:
  - `height` = popped bar's height
  - `width`  = `i` (if stack is now empty, the bar can extend all the way to the left) or `i − stack.top() − 1` (span between the new top and current index)
  - Update best area if `height × width` is larger.
- Push `i` onto the stack.

**Optimizations over the naive set-based version:**
- Avoids `heights + [0]` list copy (Python) — uses index sentinel check `i == n` instead.
- C++ uses `vector<int>` as the stack with `reserve(n+1)` for contiguous memory and better cache locality than `std::stack`.
- Uses direct comparison (`if area > best`) instead of `max()` to reduce function-call overhead.

Time complexity: **O(n)** — each index is pushed and popped at most once  
Space complexity: **O(n)** — stack holds at most `n` indices

## Files in this folder

- `problem84.py` — Python solution
- `problem84.cpp` — C++ solution
