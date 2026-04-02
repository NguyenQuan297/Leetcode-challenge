from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Sort by start; extend or append current interval
        intervals.sort(key=lambda x: x[0])
        res: List[List[int]] = [intervals[0][:]]

        for start, end in intervals[1:]:
            if start <= res[-1][1]:
                res[-1][1] = max(res[-1][1], end)
            else:
                res.append([start, end])
        return res
