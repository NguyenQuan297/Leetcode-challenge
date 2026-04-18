from collections import defaultdict
from typing import List


class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        words = set(wordList)
        if endWord not in words:
            return []

        L = len(beginWord)
        combo = defaultdict(list)
        for word in wordList:
            for i in range(L):
                combo[word[:i] + "*" + word[i + 1 :]].append(word)

        layer = {beginWord}
        parents = defaultdict(set)

        while layer:
            if endWord in layer:
                break
            words -= layer
            next_layer = set()
            for w in layer:
                for i in range(L):
                    for nei in combo[w[:i] + "*" + w[i + 1 :]]:
                        if nei in words:
                            next_layer.add(nei)
                            parents[nei].add(w)
            if not next_layer:
                return []
            layer = next_layer

        def dfs(w: str) -> List[List[str]]:
            if w == beginWord:
                return [[beginWord]]
            out: List[List[str]] = []
            for p in parents[w]:
                for seq in dfs(p):
                    out.append([*seq, w])
            return out

        return dfs(endWord)
