from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # k is the length of the unique prefix; nums[k-1] is the last kept value
        if not nums:
            return 0
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[k - 1]:
                nums[k] = nums[i]
                k += 1
        return k
