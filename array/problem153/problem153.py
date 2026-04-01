from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        # Binary search: compare mid with right to locate the rotated minimum
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] > nums[hi]:
                # Minimum is in (mid, hi]
                lo = mid + 1
            else:
                # Minimum is in [lo, mid]
                hi = mid
        return nums[lo]
