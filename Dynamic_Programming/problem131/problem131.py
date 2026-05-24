from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        # is_pal[i][j] = True if s[i..j] is a palindrome
        is_pal = [[False] * n for _ in range(n)]
        for i in range(n):
            is_pal[i][i] = True
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                is_pal[i][j] = s[i] == s[j] and (length == 2 or is_pal[i + 1][j - 1])

        result: List[List[str]] = []

        def backtrack(start: int, path: List[str]) -> None:
            if start == n:
                result.append(path.copy())
                return
            for end in range(start, n):
                if is_pal[start][end]:
                    path.append(s[start : end + 1])
                    backtrack(end + 1, path)
                    path.pop()

        backtrack(0, [])
        return result
