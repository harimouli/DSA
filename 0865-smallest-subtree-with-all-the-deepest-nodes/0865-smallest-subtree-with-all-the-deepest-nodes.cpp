/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root)
            return {0, nullptr};
        auto [d1, r1] = dfs(root->left);
        auto [d2, r2] = dfs(root->right);
        return {max(d1, d2) + 1, d1 == d2 ? root : d1 > d2 ? r1 : r2};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) { return dfs(root).second; }
};