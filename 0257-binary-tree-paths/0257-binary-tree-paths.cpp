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

    void getPath(TreeNode* root, vector<int>&temp, vector<string>&res){

        if(root->left == nullptr && root->right == nullptr) {
            temp.push_back(root->val);
            string t = "";
            for(int i = 0; i<temp.size(); i++){
                if(i != temp.size()-1){
                    t = t + to_string(temp[i]) + "->";
                }else{
                    t = t + to_string(temp[i]);
                }
            }
            temp.pop_back();
            res.push_back(t);
            return;
        }
        temp.push_back(root->val);
        if(root->left) getPath(root->left, temp, res);
        
        if(root->right) getPath(root->right, temp, res);
        temp.pop_back();

       
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        vector<int> temp;
        getPath(root, temp, res);
        return res;

    }
};