class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        # Sort, then for each anchor i find pairs (lo, hi) with nums[lo]+nums[hi] == -nums[i]
        nums.sort()
        n = len(nums)
        res: list[list[int]] = []
        for i in range(n - 2):
            # Skip duplicate anchors so triplets stay unique
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            lo, hi = i + 1, n - 1
            while lo < hi:
                s = nums[lo] + nums[hi]
                if s < target:
                    lo += 1
                elif s > target:
                    hi -= 1
                else:
                    res.append([nums[i], nums[lo], nums[hi]])
                    lo += 1
                    hi -= 1
                    while lo < hi and nums[lo] == nums[lo - 1]:
                        lo += 1
                    while lo < hi and nums[hi] == nums[hi + 1]:
                        hi -= 1
        return res
