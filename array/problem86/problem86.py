from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: "Optional[ListNode]" = None):
        self.val  = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        less_dummy    = ListNode()
        greater_dummy = ListNode()
        less          = less_dummy
        greater       = greater_dummy

        node = head
        while node:
            if node.val < x:
                less.next = node
                less      = less.next
            else:
                greater.next = node
                greater      = greater.next
            node = node.next

        greater.next  = None               # terminate greater list
        less.next     = greater_dummy.next # join the two lists
        return less_dummy.next
