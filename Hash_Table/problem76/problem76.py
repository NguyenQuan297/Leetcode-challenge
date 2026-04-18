from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need: Counter[str] = Counter(t)
        missing = len(t)
        left = 0
        start = 0
        best = float("inf")

        for right, ch in enumerate(s):
            if need[ch] > 0:
                missing -= 1
            need[ch] -= 1
            while missing == 0:
                if right - left + 1 < best:
                    best = right - left + 1
                    start = left
                c = s[left]
                if need[c] == 0:
                    missing += 1
                need[c] += 1
                left += 1

        return "" if best == float("inf") else s[start : start + best]
