from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Track seen digits per row, column, and 3x3 box (only filled cells matter)
        rows: list[set[str]] = [set() for _ in range(9)]
        cols: list[set[str]] = [set() for _ in range(9)]
        boxes: list[set[str]] = [set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                ch = board[i][j]
                if ch == ".":
                    continue
                b = (i // 3) * 3 + (j // 3)
                if ch in rows[i] or ch in cols[j] or ch in boxes[b]:
                    return False
                rows[i].add(ch)
                cols[j].add(ch)
                boxes[b].add(ch)
        return True
