from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp: List[List[str]] = [[] for _ in range(n + 1)]
        dp[0] = [""]

        for k in range(1, n + 1):
            cur: List[str] = []
            for i in range(k):
                for left in dp[i]:
                    for right in dp[k - 1 - i]:
                        cur.append("(" + left + ")" + right)
            dp[k] = cur

        return dp[n]
