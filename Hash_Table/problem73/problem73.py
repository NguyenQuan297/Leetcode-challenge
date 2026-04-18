from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        row0 = any(matrix[0][c] == 0 for c in range(n))
        col0 = any(matrix[r][0] == 0 for r in range(m))

        for r in range(1, m):
            for c in range(1, n):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0

        for r in range(1, m):
            if matrix[r][0] == 0:
                for c in range(n):
                    matrix[r][c] = 0

        for c in range(1, n):
            if matrix[0][c] == 0:
                for r in range(m):
                    matrix[r][c] = 0

        if row0:
            for c in range(n):
                matrix[0][c] = 0
        if col0:
            for r in range(m):
                matrix[r][0] = 0
