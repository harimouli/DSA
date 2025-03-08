class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int right = k-1;
        int n = blocks.size();
        int ans = INT_MAX;
        while(right < n){

            int count = 0;
            for(int  i = left; i<=right; i++){
                if(blocks[i] == 'W'){
                    count++;
                }
            }
            left++;
            right++;
            ans = min(ans, count);
        }
        return ans;
    }
};