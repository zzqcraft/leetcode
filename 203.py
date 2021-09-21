# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        newHead = ListNode()
        newHead.next = head
        head = newHead
        while head.next is not None:
            if head.next.val == val:
                head.next = head.next.next
            else:
                head = head.next
        return newHead.next
