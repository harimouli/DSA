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
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(cur1 && cur2){
            if(cur1->val < cur2->val){
                    temp ->next = new ListNode(cur1->val);
                    temp = temp->next;
                    cur1 = cur1->next;
            }
            else{
                temp->next = new ListNode(cur2 ->val);
                temp = temp->next;
                cur2 = cur2->next;
            }
        }
        while(cur1){
             temp ->next = new ListNode(cur1->val);
             temp = temp->next;
            cur1 = cur1->next;
        }
        while(cur2){
            temp->next = new ListNode(cur2 ->val);
            temp = temp ->next;
            cur2 = cur2->next;
        }
        return head->next;
    }
};