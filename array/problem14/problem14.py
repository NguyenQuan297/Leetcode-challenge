from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # Compare column by column using the first string as reference
        if not strs:
            return ""
        first = strs[0]
        for i, c in enumerate(first):
            for s in strs[1:]:
                # Mismatch or shorter string ends the common prefix at index i
                if i >= len(s) or s[i] != c:
                    return first[:i]
        return first
