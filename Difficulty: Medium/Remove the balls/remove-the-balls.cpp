class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
       
       
       
       int n = color.size();
       stack<pair<int, int>> stk;
       int numberOfBalls = n;
       
       for(int i = 0; i<n; i++){
           
           if(!stk.empty()  && (stk.top().first == color[i]) && (stk.top().second == radius[i])){
                  while(!stk.empty() && stk.top().first == color[i] && stk.top().second == radius[i])
                  {
                    stk.pop();
                  }   
           }
           else {
                stk.push({color[i], radius[i]});   
           }
       }
        return stk.size();
    }
};