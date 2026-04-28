class Solution:
    def numDecodings(self, s: str) -> int:
        prev2 = 1
        prev1 = 0 if s[0] == "0" else 1

        for i in range(2, len(s) + 1):
            cur = 0
            if s[i - 1] != "0":
                cur += prev1
            two = int(s[i - 2 : i])
            if 10 <= two <= 26:
                cur += prev2
            prev2, prev1 = prev1, cur

        return prev1
