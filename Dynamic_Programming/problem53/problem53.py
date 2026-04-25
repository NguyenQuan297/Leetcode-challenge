from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        it = iter(nums)
        first = next(it)
        cur = first
        best = first

        for x in it:
            cur = max(x, cur + x)
            best = max(best, cur)

        return best
