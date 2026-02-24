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
    int f(TreeNode* root, int currentSum) {
        if (!root) return 0;

       
        currentSum = (currentSum * 2) + root->val;

       
        if (!root->left && !root->right) {
            return currentSum;
        }

       
        return f(root->left, currentSum) + f(root->right, currentSum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return f(root, 0);
    }
};