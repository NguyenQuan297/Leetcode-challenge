from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # XOR indices 0..n-1 and values with n: pairs (i, nums[i]) cancel except missing
        n = len(nums)
        x = n
        for i, v in enumerate(nums):
            x ^= i ^ v
        return x
