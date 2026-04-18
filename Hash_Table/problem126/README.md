# 126. Word Ladder II

**Topic:** [Hash Table](../) · **Difficulty:** Hard

## Description

Same transformation rules as [127. Word Ladder](../problem127/): each step changes **exactly one letter**; every intermediate word must be in `wordList`; `beginWord` need not be in `wordList`; last word must be `endWord`.

Return **all shortest** transformation sequences from `beginWord` to `endWord`. Each sequence is a list `[beginWord, s1, …, sk]`. If none exist, return `[]`.

## Examples

**Example 1:**

- Input: `beginWord = "hit"`, `endWord = "cog"`, `wordList = ["hot","dot","dog","lot","log","cog"]`
- Output: `[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]`

**Example 2:**

- Input: `beginWord = "hit"`, `endWord = "cog"`, `wordList = ["hot","dot","dog","lot","log"]`
- Output: `[]`

## Constraints

- `1 <= beginWord.length <= 5`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 500`
- Same length, lowercase letters; `beginWord != endWord`; words unique.
- The **total number of words** across all shortest sequences ≤ `10^5`.

## Approach

**BFS by layer:** keep a **hash set** of remaining dictionary words. Each BFS level is a set `layer` of words at the same distance from `beginWord`. If `endWord` appears in `layer`, stop (shortest length found). Otherwise remove `layer` from the word set (so edges only go “forward” on a shortest-length layering) and build the next frontier.

**Pattern buckets (Python):** precompute a **hash map** `pattern → [words]` where `pattern = word[:i] + '*' + word[i+1:]`. Any two words sharing a pattern are one-letter neighbors at position `i`. Expanding neighbors by scanning those lists avoids trying all **26** letters at each position (same asymptotics, usually faster on LeetCode for dense `wordList`).

**Parents graph:** `parents[nw]` = set of previous-layer words `w` with a shortest edge into `nw`.

**DFS:** from `endWord` walk `parents` to `beginWord`; build each path with `[*seq, w]` (or reverse a backward buffer in C++).

Time is dominated by BFS + output size; space **O(N)** for sets/maps plus answer.

## Files in this folder

- `problem126.py` — Python solution
- `problem126.cpp` — C++ solution
