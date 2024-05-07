# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def doubleIt(self, head):
        if head is None:
            return None
        if head.val == 0:
            return ListNode(0)
        
        temp = head
        s = ""

        # Traverse the linked list and convert values to string
        while temp is not None:
            s += chr(temp.val + ord('0'))
            temp = temp.next

        # Convert the string to an integer and double it
        num = int(s)
        num *= 2
        s = str(num)

        newHead = None
        tail = None

        # Create new linked list using the doubled number
        for i in range(len(s)):
            data = int(s[i])
            node = ListNode(data)
            if newHead is None:
                newHead = node
                tail = node
            tail.next = node
            tail = node
        tail.next = None

        return newHead
        