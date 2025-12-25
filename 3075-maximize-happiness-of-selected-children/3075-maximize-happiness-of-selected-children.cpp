class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        int turns = 0;
        int  n = happiness.size() - 1;
        sort(happiness.begin(), happiness.end());
        long long  maxSum = 0;
        int  ind = n;
        while( k){
            if(happiness[ind] - turns <=0) return maxSum;
            maxSum  += (happiness[ind] - turns);
            turns += 1;
            ind -= 1;
            k--;
        }

        return maxSum;
    }
};