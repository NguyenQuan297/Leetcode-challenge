# 22. Generate Parentheses

**Topic:** [Dynamic Programming](../) · **Difficulty:** Medium

## Description

Given `n` pairs of parentheses, return all combinations of **well-formed** parentheses.

## Examples

**Example 1:**

- Input: `n = 3`
- Output: `["((()))","(()())","(())()","()(())","()()()"]`

**Example 2:**

- Input: `n = 1`
- Output: `["()"]`

## Constraints

- `1 <= n <= 8`

## Approach

Use DP where `dp[k]` stores all valid strings with `k` pairs.

For each `k` from `1` to `n`, split into:

- inside pair: `i` pairs
- remaining suffix: `k - 1 - i` pairs

Then combine:

- `"(" + left + ")" + right`
- for every `left` in `dp[i]`, every `right` in `dp[k - 1 - i]`

Base case: `dp[0] = [""]`.

This is the Catalan construction, generating exactly all valid forms without duplicates.

Time is proportional to output size (Catalan numbers), with extra combination overhead.

## Files in this folder

- `problem22.py` — Python solution
- `problem22.cpp` — C++ solution
