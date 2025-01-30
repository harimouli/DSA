class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int L1 = INT_MIN;
        int L2 = INT_MIN;
        int m1 = 0;
        int m2 = 0;
        for(int i = 0; i<n; i++){
            if(m1 == 0 && nums[i] != L2 ){
                L1 = nums[i];
                m1 += 1;
            }
            else if(m2 == 0 && nums[i] != L1){
                L2 = nums[i];
                m2 +=1;
            }
            else if(L1 == nums[i]){
                m1 += 1;
            }
            else if(L2 == nums[i]){
                m2 += 1;
            }
            else{
                m1 -=1;
                m2 -= 1;
            }
        }
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == L1) count1 += 1;
            if(nums[i] == L2) count2 += 1;
        }
        vector<int> ans;
        if(count1 > n / 3) ans.push_back(L1);
        if(count2 > n /3) ans.push_back(L2);
        return ans;
    }
};