class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        dp = [0] * n
        best = 0

        for i in range(1, n):
            if s[i] != ")":
                continue

            if s[i - 1] == "(":
                dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
            else:
                prev = dp[i - 1]
                j = i - prev - 1
                if j >= 0 and s[j] == "(":
                    dp[i] = prev + 2 + (dp[j - 1] if j >= 1 else 0)

            if dp[i] > best:
                best = dp[i]

        return best
