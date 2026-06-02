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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* lastGroupTail = dummy;
        ListNode* nextGroupFirst;
        int count = 1;
        while(curr){
            ListNode* tail = curr;
            while(count!=k && tail){
                count++;
                tail = tail->next;
            }
            count = 1;
            if(!tail) break;
            nextGroupFirst = tail->next;
            tail->next = nullptr;
            ListNode* reversedHead = reverseList(curr);

            lastGroupTail->next = reversedHead;
            curr->next = nextGroupFirst;
            lastGroupTail = curr;
            curr = nextGroupFirst;
        }
        return dummy->next;
    }
};
