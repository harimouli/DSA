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

    void getPath(TreeNode* root, string t, vector<string>&res){

        if(root->left == nullptr && root->right == nullptr) {
         res.push_back(t);
         return;
        }
        if(root->left) getPath(root->left, t + "->" + to_string(root->left->val), res);
        
        if(root->right) getPath(root->right, t + "->" + to_string(root->right->val), res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        getPath(root, to_string(root->val), res);
        return res;

    }
};