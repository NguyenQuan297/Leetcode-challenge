from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Use 26-letter frequency as a hashable signature for anagrams
        groups: dict[tuple[int, ...], list[str]] = {}
        for s in strs:
            cnt = [0] * 26
            for ch in s:
                cnt[ord(ch) - ord('a')] += 1
            key = tuple(cnt)
            if key not in groups:
                groups[key] = []
            groups[key].append(s)
        return list(groups.values())
