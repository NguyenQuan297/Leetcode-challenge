# 150. Evaluate Reverse Polish Notation

**Topic:** [Array](../) · **Difficulty:** Medium

## Description

Evaluate an arithmetic expression given in **Reverse Polish Notation** (RPN). Valid operators: `+`, `-`, `*`, `/`. Division truncates toward zero.

## Examples

**Example 1:**

- Input: `tokens = ["2","1","+","3","*"]`
- Output: `9`
- Explanation: `(2 + 1) * 3 = 9`

**Example 2:**

- Input: `tokens = ["4","13","5","/","+"]`
- Output: `6`
- Explanation: `4 + (13 / 5) = 6`

**Example 3:**

- Input: `tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]`
- Output: `22`

## Constraints

- `1 <= tokens.length <= 10^4`
- Each token is an operator or an integer in `[-200, 200]`.

## Approach

Use a **stack**:

- If the token is a number → push onto stack.
- If the token is an operator → pop two operands (`b` then `a`), compute `a op b`, push the result.
- Final answer is the single value remaining on the stack.

Division uses `int(a / b)` (Python) or integer division toward zero (C++) to handle truncation correctly for negatives.

Time complexity: **O(n)**  
Space complexity: **O(n)**

## Files in this folder

- `problem150.py` — Python solution
- `problem150.cpp` — C++ solution
