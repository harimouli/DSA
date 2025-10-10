/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        if (!root) return {};

        vector<int> ans;
        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            deque<int> level;  // temporary for current level

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (leftToRight) 
                    level.push_back(node->data);
                else 
                    level.push_front(node->data);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

           
            ans.insert(ans.end(), level.begin(), level.end());
            leftToRight leftToRight; 
        }

        return ans;
    }
};
