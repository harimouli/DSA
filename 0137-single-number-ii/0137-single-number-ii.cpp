class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<32; i++){
            int bitSum = 0;

            for(auto num : nums){
                if(num & (1 << i)){
                    bitSum++;
                }
            }
            int bit = bitSum % 3;
            ans = ans | (bit << i); 
        }
        return ans;
    }
};