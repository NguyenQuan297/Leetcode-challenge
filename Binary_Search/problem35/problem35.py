from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # Lower bound: first index i such that nums[i] >= target.
        # If target exists, that index is where it sits; otherwise it is the insert position.
        lo, hi = 0, len(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] < target:
                lo = mid + 1
            else:
                hi = mid
        return lo
