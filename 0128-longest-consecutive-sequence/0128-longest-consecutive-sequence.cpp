class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
       priority_queue<int> q;
       for(auto num : nums){
            q.push(num);
       }
       int count = 1;
       int maxLen = 1;
       while(!q.empty()){
            int cur = q.top();
            q.pop();
            if(cur-1 == q.top() || cur == q.top()){
                if(cur == q.top()) count;
                else count += 1;
            }
            else{
                count = 1;
            }
            maxLen = max(count, maxLen);
       }
       return maxLen;
    }
};