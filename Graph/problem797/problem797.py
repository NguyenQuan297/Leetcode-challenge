from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        target = len(graph) - 1
        result: List[List[int]] = []

        def dfs(node: int, path: List[int]) -> None:
            if node == target:
                result.append(path.copy())
                return
            for nb in graph[node]:
                path.append(nb)
                dfs(nb, path)
                path.pop()

        dfs(0, [0])
        return result
