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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast= head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = nullptr;

        ListNode* tail = head2;
        ListNode* prev = nullptr;
        while(tail){
            ListNode* temp = tail->next;
            tail->next = prev;
            prev = tail;
            tail = temp;
        }

        head2 = prev;
        ListNode dummy(0);
        tail = &dummy;
        bool flag = true;
        while(head && head2){
            if(flag){
                tail->next = head;
                head = head->next;
                tail = tail->next;
                flag = false;
            }else{
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
                flag = true;
            }
        }

        if(head){
            tail->next = head;
        }else{
            tail->next = head2;
        }
        head = dummy.next;



    }
};
