class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

            int n = nums.size();

            int sI = 1;
            int cnt = 1;

            for(int i = 1; i<n; i++){
                if(nums[i] > nums[i-1]){
                    cnt++;
                    sI = max(cnt, sI);
                }
                else cnt = 1;
            }
            if(sI / 2 >= k) return true;

            cnt = 1;

            int dip = 0;
            int prev = 0;
            for(int i = 1; i<n; i++){
                if(nums[i] > nums[i-1]){
                    cnt++;
                }
                else{
                    dip++;
                    if(dip > 0 && prev >= k && cnt >= k) return true;

                    prev = cnt;
                    cnt = 1;
                }
            }
            if(prev >= k && cnt >= k) return true;
            return false;


    }
};