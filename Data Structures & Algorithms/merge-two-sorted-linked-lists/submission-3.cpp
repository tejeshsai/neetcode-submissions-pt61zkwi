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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(0);
        ListNode* res1 = res;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while(curr1 && curr2){
            if(curr1->val < curr2->val){
                res->next =  curr1;
                curr1= curr1->next; 
            }else{
                res->next = curr2;
                curr2 = curr2->next;
            }
            res = res->next;
        }

        if(curr1){
            res->next = curr1;
        }
        else{
            res->next = curr2;
        }
        return res1->next;
    }
};
