class Solution {
public:
    void getcount(int i, vector<int> nums, int& count, int maxi, int tempor){
     if(i < 0){
        if(tempor == maxi) count++;
        return;
     }
    getcount(i-1, nums, count, maxi, tempor | nums[i]);
    getcount(i-1, nums, count, maxi, tempor);

    }
    int countMaxOrSubsets(vector<int>& nums) {

        int n = nums.size();

        int maxi = 0;

        for(int i =0; i<n; i++){
            maxi |= nums[i];
        }
        int count = 0;
        getcount(n-1,nums, count, maxi, 0);
        return count;
       
    }
};