from typing import Dict, List, Optional, Tuple


# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def generateTrees(self, n: int) -> List[Optional["TreeNode"]]:
        # Memoize trees for each value range; clone left/right when forming a new root so
        # each answer tree owns its own nodes (no sharing across the result list).
        def clone(node: Optional["TreeNode"]) -> Optional["TreeNode"]:
            if node is None:
                return None
            return TreeNode(node.val, clone(node.left), clone(node.right))

        memo: Dict[Tuple[int, int], List[Optional["TreeNode"]]] = {}

        def gen(start: int, end: int) -> List[Optional["TreeNode"]]:
            if start > end:
                return [None]
            key = (start, end)
            if key in memo:
                return memo[key]
            out: List[Optional["TreeNode"]] = []
            for i in range(start, end + 1):
                for left in gen(start, i - 1):
                    for right in gen(i + 1, end):
                        out.append(TreeNode(i, clone(left), clone(right)))
            memo[key] = out
            return out

        return gen(1, n)
