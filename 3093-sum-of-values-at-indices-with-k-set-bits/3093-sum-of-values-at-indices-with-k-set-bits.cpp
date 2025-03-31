class Solution {
public:
    int getSetBitCount(int num){
        int count = 0;

        while(num != 0){
            count++;
            num = num & (num-1);
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int n  = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(getSetBitCount(i) == k){
                ans += nums[i];
            }
        }
        return ans;
    }
};