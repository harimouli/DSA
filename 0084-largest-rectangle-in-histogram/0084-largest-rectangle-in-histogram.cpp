class Solution {
public:
    vector<int> findPSE(vector<int> &heights){
        int n = heights.size();

        vector<int> ans(n);
        stack<int> stk;

        for(int i = 0; i<n; i++){

            while(!stk.empty() && heights[stk.top()] > heights[i]){
                stk.pop();
            }

            ans[i] = !stk.empty() ? stk.top() : -1;

            stk.push(i);
        }
        return ans;
    }

    vector<int> findNSE(vector<int> &heights){
        
        int n = heights.size();
        vector<int> ans(n);
        stack<int> stk;

        for(int i = n-1; i>= 0; i--){
            

            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            ans[i] = !stk.empty() ? stk.top() : n;
            stk.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            int len = nse[i] - pse[i] - 1;
            maxArea = max(len * heights[i], maxArea);
        }
        return maxArea;
    }
};