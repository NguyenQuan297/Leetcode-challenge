from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Ensure nums1 is the shorter array so we binary search at most min(m, n) positions
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        # Left side of the virtual "merge" must contain this many elements
        total_left = (m + n + 1) // 2

        lo, hi = 0, m
        while lo <= hi:
            # i = count of elements taken from nums1 into the left partition
            i = (lo + hi) // 2
            j = total_left - i  # remaining left slots filled from nums2

            # Boundaries around the partition (use infinities when a side is empty)
            left1 = nums1[i - 1] if i > 0 else float("-inf")
            right1 = nums1[i] if i < m else float("inf")
            left2 = nums2[j - 1] if j > 0 else float("-inf")
            right2 = nums2[j] if j < n else float("inf")

            # Valid partition: every element on the left is <= every element on the right
            if left1 <= right2 and left2 <= right1:
                if (m + n) % 2 == 1:
                    return float(max(left1, left2))
                return (max(left1, left2) + min(right1, right2)) / 2.0

            # Too many elements from nums1 on the left; move partition left in nums1
            if left1 > right2:
                hi = i - 1
            else:
                lo = i + 1

        raise RuntimeError("unreachable: inputs guarantee a median exists")
