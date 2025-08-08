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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        

        ListNode* temp = head;

        for(int i = 1; i<left; i++){
          temp = temp->next;
         
        }
        if(temp == nullptr) return head;
        stack<int> stk;
        ListNode* dummy = temp;
        for(int i = 0; i<(right - left + 1); i++) {
            stk.push(dummy->val);
            dummy = dummy->next;
        }
        cout<<stk.top();
        for(int i = 0; i<=(right - left); i++){
            temp->val = stk.top();
            temp = temp->next;
            stk.pop();
        }

        return head;
    }
};