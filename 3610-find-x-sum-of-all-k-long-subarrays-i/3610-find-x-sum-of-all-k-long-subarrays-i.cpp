class Solution {
public:

    int getXSum(int left, int right, int x,vector<int> &nums){

        unordered_map<int, int>mpp;

        for(int i = left; i<=right; i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto &pair : mpp){
            int num = pair.first;
            int freq = pair.second;
            pq.push({freq, num});

            while(pq.size() > x){
                pq.pop();
            }
        }

        int value = 0;

        while(!pq.empty()){
            value += pq.top().second * pq.top().first;
            pq.pop();
        }
        return value;

    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        


        int left = 0;
        int n = nums.size();

        vector<int> ans;
        for(int right = 0; right<n; right++){
            
            if(right - left + 1 == k){
                int sum = getXSum(left, right, x,nums);
                ans.push_back(sum);
                left++;
            }
        }
        return ans;
    }
};