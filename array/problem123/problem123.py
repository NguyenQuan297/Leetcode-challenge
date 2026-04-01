from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # DP with 4 states (at most 2 transactions):
        # buy1  = max profit after first buy
        # sell1 = max profit after first sell
        # buy2  = max profit after second buy
        # sell2 = max profit after second sell
        buy1 = float("-inf")
        sell1 = 0
        buy2 = float("-inf")
        sell2 = 0

        for p in prices:
            buy1 = max(buy1, -p)
            sell1 = max(sell1, buy1 + p)
            buy2 = max(buy2, sell1 - p)
            sell2 = max(sell2, buy2 + p)

        return sell2
