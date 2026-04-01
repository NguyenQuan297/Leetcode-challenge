from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Track the minimum price seen so far and best profit ending today
        min_price = prices[0]
        best = 0
        for p in prices[1:]:
            if p < min_price:
                min_price = p
            else:
                best = max(best, p - min_price)
        return best
