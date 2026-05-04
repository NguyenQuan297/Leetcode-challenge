class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        if n == 1:
            return "".join(str(i) for i in range(k))

        total = k ** n          # total edges = total passwords
        highK = k ** (n - 1)    # total nodes
        visited = [False] * total
        result = []

        def dfs(node: int):
            for d in range(k):
                edge = node * k + d
                if not visited[edge]:
                    visited[edge] = True
                    dfs(edge % highK)   # next node
                    result.append(str(d))

        dfs(0)
        result.append("0" * (n - 1))
        return "".join(reversed(result))