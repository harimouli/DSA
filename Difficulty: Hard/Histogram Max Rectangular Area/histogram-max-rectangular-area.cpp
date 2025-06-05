class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        
        
        
        int n = arr.size();
        
        stack<int> stk;
        
        int maxArea = 0;
        
        for(int i = 0; i<n; i++){
            
            
            while(!stk.empty() && arr[stk.top()]  >= arr[i]){
                
                int index = stk.top();
                stk.pop();
                
                int pse = stk.empty() ? -1 :stk.top(); 
                
                int area = arr[index] * (i - pse -1);
                maxArea = max(maxArea, area);
                
            }
            
            stk.push(i);
        }
        
        
        while(!stk.empty()){
            int index = stk.top();
            stk.pop();
            int pse = stk.empty() ? -1: stk.top();
            maxArea = max(maxArea, (arr[index] * (n - pse - 1)));
        }
        
        return maxArea;
        
    }
};
