/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        int carry = 0;
        int sum = 0;
        while(curr1!=nullptr || curr2!=nullptr || carry!=0){
            int val1 = curr1 ? curr1->val : 0;
            int val2 = curr2 ? curr2->val : 0;
            sum = val1+val2+carry;

            carry = sum/10;
            tail->next = new ListNode(sum%10);
            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
            tail = tail->next;
        }

        
        return dummy.next;
    }
};
