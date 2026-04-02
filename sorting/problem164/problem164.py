from typing import List


class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        # LSD radix sort by bytes: O(4 * (n + 256)) time, O(n) extra space
        arr = nums[:]
        for shift in range(0, 32, 8):
            buckets: list[list[int]] = [[] for _ in range(256)]
            for x in arr:
                buckets[(x >> shift) & 0xFF].append(x)
            arr = []
            for b in buckets:
                arr.extend(b)
        return max(arr[i + 1] - arr[i] for i in range(len(arr) - 1))
