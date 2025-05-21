class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        

        int n = nums.size();

        stack<int> stk;

        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){

                while(!stk.empty() && stk.top() <= nums[i]){
                    stk.pop();
                }
                if(stk.empty()){
                    ans[i] = INT_MIN;
                }
                else{
                    ans[i] = stk.top();
                }
                stk.push(nums[i]);
        }


        for(int i = n-1; i >= 0; i--){
            stk.push(nums[i]);
        }

        for(int i = n -1; i>= 0; i--){
            

            if(ans[i] == INT_MIN){

                while(!stk.empty() && stk.top() <= nums[i]){
                    stk.pop();
                }
                if(!stk.empty()){
                    ans[i] = stk.top();
                }

            }
        }

    for(int i = 0; i<n; i++){
        if(ans[i] == INT_MIN) ans[i] = -1;
    }

    return ans;

    }
};