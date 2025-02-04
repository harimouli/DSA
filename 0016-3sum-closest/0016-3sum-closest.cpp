class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cSum = INT_MAX/ 2;
       for(int i =0; i<n; i++){
            int j = i + 1;
            int k = n - 1;
            while(j <k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-  target) < abs(cSum - target)){
                    cSum = sum;
                }
                if(sum > target){
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else {
                    return sum;
                }
            }
       }
       return cSum;
    }
};