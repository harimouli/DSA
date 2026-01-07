/**
 * Definition for a binary tree node.
 * struct TreeNode {
\ *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int MOD = 1e9 + 7;
     long long ans = 0;
    long long    getMaxProduct(TreeNode* root, int totalSum){
        if(!root) return 0;
        long long   left = getMaxProduct(root->left, totalSum);
        long long  right = getMaxProduct(root->right, totalSum);
         long long    value = root->val + left + right;
        ans = max(ans, (totalSum - value) * value);
        return value;
    }
    long long getTotalSum(TreeNode* root){
        if(!root) return 0;

        long long  left = getTotalSum(root->left);

        long long  right =  getTotalSum(root->right);
        return root->val + left + right;
    }
    int maxProduct(TreeNode* root) {
       
        if(!root) return 0;
        int totalSum = getTotalSum(root);
        // inorder Traversal 
        
        getMaxProduct(root, totalSum);
        return ans % MOD;
    }
};