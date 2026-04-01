from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows: list[set[str]] = [set() for _ in range(9)]
        cols: list[set[str]] = [set() for _ in range(9)]
        boxes: list[set[str]] = [set() for _ in range(9)]
        # Pre-fill sets from clues so we only try digits not already used in row/col/box
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    ch = board[i][j]
                    rows[i].add(ch)
                    cols[j].add(ch)
                    boxes[(i // 3) * 3 + (j // 3)].add(ch)

        def dfs() -> bool:
            for i in range(9):
                for j in range(9):
                    if board[i][j] != ".":
                        continue
                    b = (i // 3) * 3 + (j // 3)
                    for d in "123456789":
                        if d in rows[i] or d in cols[j] or d in boxes[b]:
                            continue
                        board[i][j] = d
                        rows[i].add(d)
                        cols[j].add(d)
                        boxes[b].add(d)
                        if dfs():
                            return True
                        board[i][j] = "."
                        rows[i].remove(d)
                        cols[j].remove(d)
                        boxes[b].remove(d)
                    return False
            return True

        dfs()
