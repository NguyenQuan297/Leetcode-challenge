from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Each row is sorted: binary search within the row (O(log n) per row).
        # Column order lets us skip rows or stop early (O(m log n) overall).
        for row in matrix:
            if row[0] > target:
                break
            if row[-1] < target:
                continue
            lo, hi = 0, len(row) - 1
            while lo <= hi:
                mid = (lo + hi) // 2
                if row[mid] == target:
                    return True
                if row[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid - 1
        return False
