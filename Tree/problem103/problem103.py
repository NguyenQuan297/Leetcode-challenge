from collections import deque
from typing import List, Optional


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def zigzagLevelOrder(self, root: Optional["TreeNode"]) -> List[List[int]]:
        if root is None:
            return []
        res: List[List[int]] = []
        q: deque = deque([root])
        depth = 0
        while q:
            level: List[int] = []
            for _ in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if depth % 2 == 1:
                level.reverse()
            res.append(level)
            depth += 1
        return res
