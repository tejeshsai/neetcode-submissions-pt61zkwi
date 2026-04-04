# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or head.next == None :
            return head
        new_list_head = ListNode(-10001)
        curr = head
        while curr:
            new_node = ListNode(curr.val)
            new_node.next = new_list_head
            new_list_head = new_node
            curr = curr.next
        curr = new_list_head
        while curr.next.val != -10001:
            curr = curr.next
        curr.next = None
        return new_list_head

            