from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        # With duplicates, worst-case can degrade to O(n) when boundaries are equal
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] < nums[hi]:
                hi = mid
            elif nums[mid] > nums[hi]:
                lo = mid + 1
            else:
                # nums[mid] == nums[hi], cannot decide side; shrink safely
                hi -= 1
        return nums[lo]
