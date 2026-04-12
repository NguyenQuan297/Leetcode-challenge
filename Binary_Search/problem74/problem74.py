from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Rows and columns form one sorted sequence: index k maps to matrix[k // n][k % n].
        m = len(matrix)
        n = len(matrix[0])
        lo, hi = 0, m * n - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            val = matrix[mid // n][mid % n]
            if val == target:
                return True
            if val < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return False
