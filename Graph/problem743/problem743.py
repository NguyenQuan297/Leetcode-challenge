from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        INF = float("inf")
        dist = [INF] * (n + 1)
        dist[k] = 0

        # Build adjacency as flat edge list for cache-friendly scan
        adj: list[list[tuple[int, int]]] = [[] for _ in range(n + 1)]
        for u, v, w in times:
            adj[u].append((v, w))

        visited = [False] * (n + 1)

        # Array-based Dijkstra: O(V²) — faster than heap for n <= 100
        for _ in range(n):
            u = -1
            for i in range(1, n + 1):
                if not visited[i] and (u == -1 or dist[i] < dist[u]):
                    u = i
            if dist[u] == INF:
                break
            visited[u] = True
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        ans = max(dist[1:])
        return -1 if ans == INF else ans
