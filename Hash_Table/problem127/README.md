# 127. Word Ladder

**Topic:** [Hash Table](../) · **Difficulty:** Hard

## Description

A **transformation sequence** from `beginWord` to `endWord` using dictionary `wordList` is a sequence  
`beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair differs by **exactly one letter**.
- Each `si` for `1 <= i <= k` is in `wordList` (`beginWord` does **not** need to be in `wordList`).
- `sk == endWord`.

Return the **number of words** in the **shortest** valid transformation sequence, or `0` if none exists.

## Examples

**Example 1:**

- Input: `beginWord = "hit"`, `endWord = "cog"`, `wordList = ["hot","dot","dog","lot","log","cog"]`
- Output: `5`
- Explanation: e.g. `"hit" -> "hot" -> "dot" -> "dog" -> "cog"` (5 words).

**Example 2:**

- Input: `beginWord = "hit"`, `endWord = "cog"`, `wordList = ["hot","dot","dog","lot","log"]`
- Output: `0`
- Explanation: `"cog"` is not in `wordList`.

## Constraints

- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- All words same length; lowercase letters; `beginWord != endWord`; words in `wordList` are unique.

## Approach

Model words as **nodes**; an edge exists between two words if they differ by one character. Shortest path ⇒ **BFS** from `beginWord`.

Store `wordList` in a **hash set** (`set` / `unordered_set`) for **O(1)** membership when generating neighbors (change one position to `a`..`z`). Remove a word from the set when it is **enqueued** so each word is visited at most once at the **first** (shortest) depth. Time **O(N · L · 26)** with alphabet size constant, space **O(N)** for the set and queue.

## Files in this folder

- `problem127.py` — Python solution
- `problem127.cpp` — C++ solution
