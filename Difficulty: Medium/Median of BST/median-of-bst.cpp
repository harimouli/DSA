/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

void getValues(Node* root, vector<int>&values){
    
    if(!root) return;
    
    if(root->left) getValues(root->left, values);
    values.push_back(root->data);
    if(root->right) getValues(root->right, values);
}

class Solution {
  public:
    int findMedian(Node* root) {
       vector<int>values;
       
       getValues(root, values);
       
       if(values.size() % 2) {
           int index = (values.size() + 1) / 2;
           return values[index-1];
       }
       int index = (values.size()) / 2;
       return values[index - 1];
    }
};