class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # last index of each character in the current window context
        last: dict[str, int] = {}
        left = 0
        best = 0
        for right, ch in enumerate(s):
            if ch in last and last[ch] >= left:
                left = last[ch] + 1
            last[ch] = right
            best = max(best, right - left + 1)
        return best
