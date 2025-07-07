class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int>ans(n);
        for(int i = 2*n-1; i>= 0; i--){
            
            while(!stk.empty() && stk.top() <= arr[i % n]){
                stk.pop();
            }
           
            ans[i%n] = stk.empty() ? -1 : stk.top();
            stk.push(arr[i % n]);
        }
        return ans;
        
    }
};

