from typing import Optional


class Node:
    def __init__(self, val: int = 0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
        if not node:
            return None

        visited: dict[Node, Node] = {}

        def dfs(n: Node) -> Node:
            if n in visited:
                return visited[n]
            clone = Node(n.val)
            visited[n] = clone
            for nb in n.neighbors:
                clone.neighbors.append(dfs(nb))
            return clone

        return dfs(node)
