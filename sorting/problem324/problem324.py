from typing import List


class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Sort, then place smaller half at even indices and larger half at odd indices,
        # both halves taken from the end inward so duplicates do not sit next to each other.
        nums.sort()
        n = len(nums)
        mid = (n + 1) // 2
        left = nums[:mid][::-1]
        right = nums[mid:][::-1]
        nums[::2] = left
        nums[1::2] = right
