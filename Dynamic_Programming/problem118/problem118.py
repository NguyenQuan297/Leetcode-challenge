from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = [[1]]

        for i in range(1, numRows):
            prev = triangle[i - 1]
            row = [1] + [prev[j] + prev[j + 1] for j in range(len(prev) - 1)] + [1]
            triangle.append(row)

        return triangle
