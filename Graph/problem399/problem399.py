from collections import defaultdict, deque
from typing import List


class Solution:
    def calcEquation(
        self,
        equations: List[List[str]],
        values: List[float],
        queries: List[List[str]],
    ) -> List[float]:
        graph: dict[str, list[tuple[str, float]]] = defaultdict(list)

        for (a, b), v in zip(equations, values):
            graph[a].append((b, v))
            graph[b].append((a, 1.0 / v))

        def bfs(src: str, dst: str) -> float:
            if src not in graph or dst not in graph:
                return -1.0
            if src == dst:
                return 1.0
            visited = {src}
            queue = deque([(src, 1.0)])
            while queue:
                node, prod = queue.popleft()
                for nb, w in graph[node]:
                    if nb == dst:
                        return prod * w
                    if nb not in visited:
                        visited.add(nb)
                        queue.append((nb, prod * w))
            return -1.0

        return [bfs(c, d) for c, d in queries]
