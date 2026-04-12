from typing import List, Optional


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def inorderTraversal(self, root: Optional["TreeNode"]) -> List[int]:        # Iterative inorder (Left -> Root -> Right): descend left pushing nodes, then pop, visit, go right.
        res: List[int] = []
        stack: list = []
        cur = root
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            res.append(cur.val)
            cur = cur.right
        return res
