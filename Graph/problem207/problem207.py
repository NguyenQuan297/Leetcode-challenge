from collections import deque
from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj: List[List[int]] = [[] for _ in range(numCourses)]

        for a, b in prerequisites:
            adj[b].append(a)
            indegree[a] += 1

        queue = deque(i for i in range(numCourses) if indegree[i] == 0)
        processed = 0

        while queue:
            node = queue.popleft()
            processed += 1
            for nb in adj[node]:
                indegree[nb] -= 1
                if indegree[nb] == 0:
                    queue.append(nb)

        return processed == numCourses
