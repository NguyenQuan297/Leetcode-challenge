from typing import List


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        cols    = len(matrix[0])
        heights = [0] * cols
        best    = 0

        for row in matrix:
            # Update histogram heights
            for c in range(cols):
                heights[c] = heights[c] + 1 if row[c] == "1" else 0

            # Largest rectangle in histogram (monotonic stack, inline sentinel)
            stack: List[int] = []
            for i in range(cols + 1):
                h = heights[i] if i < cols else 0
                while stack and heights[stack[-1]] > h:
                    height = heights[stack.pop()]
                    width  = i if not stack else i - stack[-1] - 1
                    area   = height * width
                    if area > best:
                        best = area
                stack.append(i)

        return best
