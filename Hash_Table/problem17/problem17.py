from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        pad: dict[str, str] = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        out: list[str] = [""]
        for d in digits:
            letters = pad[d]
            out = [p + c for p in out for c in letters]
        return out
