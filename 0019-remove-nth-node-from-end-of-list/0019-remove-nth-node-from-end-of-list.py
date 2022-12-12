# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        l,c,p = head,head,None
        while n:
            l = l.next
            n -= 1
            
        while l:
            l = l.next
            p = c
            c = c.next
            
        if not p:
            return c.next
        
        p.next = c.next
        
        return head