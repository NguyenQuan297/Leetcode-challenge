from collections import deque
from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0] * numCourses
        adj: List[List[int]] = [[] for _ in range(numCourses)]

        for a, b in prerequisites:
            adj[b].append(a)
            indegree[a] += 1

        queue = deque(i for i in range(numCourses) if indegree[i] == 0)
        order: List[int] = []

        while queue:
            node = queue.popleft()
            order.append(node)
            for nb in adj[node]:
                indegree[nb] -= 1
                if indegree[nb] == 0:
                    queue.append(nb)

        return order if len(order) == numCourses else []
