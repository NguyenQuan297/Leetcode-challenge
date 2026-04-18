from collections import Counter
from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words or not s:
            return []
        wlen = len(words[0])
        n = len(words)
        total = wlen * n
        if len(s) < total:
            return []

        need: Counter[str] = Counter(words)
        out: list[int] = []

        for offset in range(wlen):
            left = offset
            cur: Counter[str] = Counter()
            matched = 0
            for j in range(offset, len(s) - wlen + 1, wlen):
                word = s[j : j + wlen]
                if word in need:
                    cur[word] += 1
                    matched += 1
                    while cur[word] > need[word]:
                        lw = s[left : left + wlen]
                        cur[lw] -= 1
                        if cur[lw] == 0:
                            del cur[lw]
                        matched -= 1
                        left += wlen
                    if matched == n:
                        out.append(left)
                        lw = s[left : left + wlen]
                        cur[lw] -= 1
                        if cur[lw] == 0:
                            del cur[lw]
                        matched -= 1
                        left += wlen
                else:
                    cur.clear()
                    matched = 0
                    left = j + wlen

        return out
