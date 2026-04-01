from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # XOR cancels pairs: a ^ a = 0, and 0 ^ x = x
        x = 0
        for v in nums:
            x ^= v
        return x
