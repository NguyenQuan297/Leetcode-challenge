from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]] :
        full = (1 << n) - 1
        queens: List[int] = []
        result: List[List[str]] = []

        def backtrack(cols: int, d1: int, d2: int) -> None:
            if cols == full:
                board = ["." * q + "Q" + "." * (n - q - 1) for q in queens]
                result.append(board)
                return
            avail = full & ~(cols | d1 | d2)
            while avail:
                b = avail & (-avail)          # isolate lowest set bit
                avail ^= b
                col = b.bit_length() - 1
                queens.append(col)
                backtrack(cols | b, (d1 | b) >> 1, (d2 | b) << 1)
                queens.pop()

        backtrack(0, 0, 0)
        return result
