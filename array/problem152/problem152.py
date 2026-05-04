from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        cur_max = cur_min = best = nums[0]

        for x in nums[1:]:
            prev_max = cur_max
            cur_max = max(x, prev_max * x, cur_min * x)
            cur_min = min(x, prev_max * x, cur_min * x)
            if cur_max > best:
                best = cur_max

        return best
