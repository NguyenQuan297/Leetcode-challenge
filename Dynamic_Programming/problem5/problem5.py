class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n <= 1:
            return s

        start = 0
        max_len = 0

        def expand(left: int, right: int) -> None:
            nonlocal start, max_len
            while left >= 0 and right < n and s[left] == s[right]:
                length = right - left + 1
                if length > max_len:
                    max_len = length
                    start = left
                left -= 1
                right += 1

        for i in range(n):
            expand(i, i)
            expand(i, i + 1)

        return s[start : start + max_len]
