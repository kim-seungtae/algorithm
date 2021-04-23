# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        size = 1
        cur = head
        while cur.next != None:
            size += 1
            cur = cur.next
        if size == 1:
            return None
        
        if size == n:
            return head.next
        
        pred = head
        
        moveCnt = size - n - 1
        for i in range(moveCnt):
            pred = pred.next
        
        succ = pred.next
        if succ != None:
            succ = succ.next
            
        pred.next = succ
        
        
        return head
        