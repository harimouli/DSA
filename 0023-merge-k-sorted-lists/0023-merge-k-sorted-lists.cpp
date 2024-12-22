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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int k = lists.size();
         if(k==0){
            return nullptr;
         }
         if(k == 1){
            return lists[0];
         }

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i = 0; i<k; i++){
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ListNode* cur = top.second;
            temp->next = cur;
            temp = temp->next;
            if(cur->next) pq.push({cur->next->val, cur->next});
        }
        return dummy->next;

    }
};