from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]

        n = len(nums)
        lo, hi = 0, n - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] < target:
                lo = mid + 1
            else:
                hi = mid
        if nums[lo] != target:
            return [-1, -1]
        first = lo

        lo, hi = 0, n - 1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if nums[mid] > target:
                hi = mid - 1
            else:
                lo = mid
        return [first, lo]
