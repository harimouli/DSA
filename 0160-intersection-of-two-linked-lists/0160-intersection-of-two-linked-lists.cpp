/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode* , int> mpp;


        while(headA != nullptr || headB != nullptr){

            if(headA != nullptr) mpp[headA]++;
            if(headB != nullptr) mpp[headB]++;

           if(headA) headA = headA->next;
            if(headB) headB = headB->next;
        }


        for(auto &pair : mpp){
            if(pair.second > 1) return pair.first;
        }
        return nullptr;
    }
};