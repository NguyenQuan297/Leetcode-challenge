from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # k points to the next write position
        k = 0
        for x in nums:
            # keep x if we have written fewer than 2 copies of x
            # or x differs from the element written two positions back
            if k < 2 or x != nums[k - 2]:
                nums[k] = x
                k += 1
        return k
