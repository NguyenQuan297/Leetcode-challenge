from collections import deque
from typing import List


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n

        for start in range(n):
            if color[start] != -1:
                continue
            color[start] = 0
            queue = deque([start])
            while queue:
                node = queue.popleft()
                for nb in graph[node]:
                    if color[nb] == -1:
                        color[nb] = 1 - color[node]
                        queue.append(nb)
                    elif color[nb] == color[node]:
                        return False

        return True
