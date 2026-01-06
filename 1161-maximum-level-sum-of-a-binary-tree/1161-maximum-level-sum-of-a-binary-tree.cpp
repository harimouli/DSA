/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        if(!root) return 0;
        queue<TreeNode*>pq;
        pq.push(root);

        int maxSum = root->val;
        int level = 1;
        int minLevel = 1;
        while(!pq.empty()){
            int len = pq.size();
            int levelSum = 0;
            for(int i = 0; i< len; i++){
                    TreeNode* node = pq.front();
                    pq.pop();

                    levelSum += node->val;


                if(node->left) pq.push(node->left);
                if(node->right) pq.push(node->right);
            }
            
            if(levelSum > maxSum){
                maxSum = levelSum;
                minLevel = level;
            }
            level++;
        }   
        return minLevel;
        
    }
};