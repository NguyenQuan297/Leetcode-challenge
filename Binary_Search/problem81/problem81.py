from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        # Rotated sorted array with duplicates: compare mid to ends to see which side is ordered.
        # When nums[lo] == nums[mid], we cannot tell which half is sorted, so shrink lo (worst case O(n)).
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            if nums[mid] == target:
                return True
            if nums[lo] < nums[mid]:
                if nums[lo] <= target < nums[mid]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            elif nums[lo] > nums[mid]:
                if nums[mid] < target <= nums[hi]:
                    lo = mid + 1
                else:
                    hi = mid - 1
            else:
                lo += 1
        return False
