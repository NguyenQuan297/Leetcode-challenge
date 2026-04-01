from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # Sort so duplicates are adjacent; skip same value at same recursion depth
        nums.sort()
        n = len(nums)
        used = [False] * n
        res: List[List[int]] = []
        path: List[int] = []

        def dfs() -> None:
            if len(path) == n:
                res.append(path[:])
                return
            prev = None
            for i in range(n):
                if used[i]:
                    continue
                if prev is not None and nums[i] == prev:
                    continue
                prev = nums[i]
                used[i] = True
                path.append(nums[i])
                dfs()
                path.pop()
                used[i] = False

        dfs()
        return res
