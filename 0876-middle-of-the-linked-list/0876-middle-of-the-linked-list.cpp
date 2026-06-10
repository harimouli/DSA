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
    ListNode* middleNode(ListNode* head) {
        

        ListNode* temp = head;

        int count  = 0;
        while(temp != nullptr){
            count++;
           temp = temp->next;
        }

        
        int tt = count / 2;

       
            tt +=1;
        

        count = 0;
        temp = head;

        while(temp != nullptr){

            count++;
            if(count == tt){
                break;
            }
            temp = temp -> next;
        }

        return temp;
        
    }
};