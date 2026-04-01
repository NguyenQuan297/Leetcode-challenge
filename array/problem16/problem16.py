from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        # Sort, then for each i shrink the gap to target with two pointers
        nums.sort()
        n = len(nums)
        closest = nums[0] + nums[1] + nums[2]
        for i in range(n - 2):
            lo, hi = i + 1, n - 1
            while lo < hi:
                s = nums[i] + nums[lo] + nums[hi]
                if s == target:
                    return target
                if abs(s - target) < abs(closest - target):
                    closest = s
                if s < target:
                    lo += 1
                else:
                    hi -= 1
        return closest
