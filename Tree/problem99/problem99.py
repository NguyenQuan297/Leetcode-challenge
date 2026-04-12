from typing import Optional


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def recoverTree(self, root: Optional["TreeNode"]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # Morris inorder (O(1) extra space): two swaps break sorted order; track first and second anomalies.
        first: Optional["TreeNode"] = None
        second: Optional["TreeNode"] = None
        prev: Optional["TreeNode"] = None
        cur = root
        while cur:
            if cur.left:
                pre = cur.left
                while pre.right and pre.right is not cur:
                    pre = pre.right
                if pre.right is None:
                    pre.right = cur
                    cur = cur.left
                else:
                    if prev and prev.val > cur.val:
                        if first is None:
                            first = prev
                        second = cur
                    prev = cur
                    pre.right = None
                    cur = cur.right
            else:
                if prev and prev.val > cur.val:
                    if first is None:
                        first = prev
                    second = cur
                prev = cur
                cur = cur.right
        first.val, second.val = second.val, first.val
