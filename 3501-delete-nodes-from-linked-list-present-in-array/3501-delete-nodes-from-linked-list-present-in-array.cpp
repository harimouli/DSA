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

    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
            unordered_map<int, int>mpp;

           for(int num : nums){
                mpp[num]++;
           }

            

            
            ListNode* newHead = new ListNode(-1);
            ListNode* res = newHead;
            ListNode* temp = head;
            while(temp != nullptr){
                    if(mpp.find(temp->val) == mpp.end()){
                        res->next =  new ListNode(temp->val);
                        res = res->next;
                    }
                    temp = temp->next;
            }

        return newHead->next;


    }
};