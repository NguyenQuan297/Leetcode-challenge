from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # Backtracking by fixing one position at a time using in-place swaps
        res: List[List[int]] = []
        n = len(nums)

        def dfs(first: int) -> None:
            if first == n:
                res.append(nums[:])
                return
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                dfs(first + 1)
                nums[first], nums[i] = nums[i], nums[first]

        dfs(0)
        return res
