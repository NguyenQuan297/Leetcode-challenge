from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result: List[List[int]] = []

        def backtrack(start: int, remaining: int, path: List[int]) -> None:
            if remaining == 0:
                result.append(path.copy())
                return
            for i in range(start, len(candidates)):
                c = candidates[i]
                if c > remaining:
                    break
                if i > start and candidates[i] == candidates[i - 1]:
                    continue                       # skip duplicates at this depth
                path.append(c)
                backtrack(i + 1, remaining - c, path)  # i+1: each element used once
                path.pop()

        backtrack(0, target, [])
        return result
