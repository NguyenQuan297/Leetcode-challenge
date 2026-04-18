from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while (x := nums[i]) >= 1 and x <= n and nums[x - 1] != x:
                nums[i], nums[x - 1] = nums[x - 1], x
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
