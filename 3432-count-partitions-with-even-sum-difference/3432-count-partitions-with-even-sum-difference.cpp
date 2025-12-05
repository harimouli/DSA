class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>prefix(n + 1, 0);

        for(int i = 1; i<=n; i++){
            prefix[i] = prefix[i-1] +  nums[i-1];
        }

        int ans = 0;
        for(int i = 1; i<n; i++){
           int leftSum = prefix[i];
            int rightSum = prefix[n] - prefix[i];
            //cout<<leftSum<<rightSum<<endl;
            if((leftSum - rightSum)  % 2 == 0) ans++;
        }

        return ans;

    }
};