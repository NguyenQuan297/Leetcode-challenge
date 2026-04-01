from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        # Find the longest non-increasing suffix; nums[i] is the pivot to increase
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i < 0:
            nums.reverse()
            return
        # Find rightmost successor to nums[i] in the suffix (just larger than nums[i])
        j = n - 1
        while nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]
        # Make suffix the smallest ordering = reverse the non-increasing tail
        lo, hi = i + 1, n - 1
        while lo < hi:
            nums[lo], nums[hi] = nums[hi], nums[lo]
            lo += 1
            hi -= 1
