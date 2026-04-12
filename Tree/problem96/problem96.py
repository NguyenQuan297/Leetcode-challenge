class Solution:
    def numTrees(self, n: int) -> int:
        # dp[i] = number of BST shapes with i nodes (values 1..i).
        # Root j has left subtree size j-1 and right subtree size i-j.
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                dp[i] += dp[j - 1] * dp[i - j]
        return dp[n]
