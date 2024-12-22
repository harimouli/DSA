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
    ListNode* mergeLists(ListNode* head1, ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(temp1 && temp2){
            if(temp1 -> val <= temp2->val){
                cur->next = temp1;
                cur = cur->next;
                temp1 = temp1->next;
            }
            else{
                cur->next = temp2;
                cur= cur->next;
                temp2 = temp2->next;
            }
        }
        if(temp1) cur->next = temp1;
        else cur->next = temp2;
        return dummy ->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return nullptr;
        if(k == 1) return lists[0];
        ListNode* head = lists[0];
        for(int i = 1; i<k; i++){
            head = mergeLists(head, lists[i]);
        }
        return head;
    }
};