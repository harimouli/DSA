class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        long long ans = 0;
        while(low <= high){
            
            long long  mid = low + (high - low) /  2;

            long long  childrenCount = 0;
            for(auto pile : candies){
                childrenCount += pile / mid;
            }
            if(childrenCount >= k){
                ans = mid;
                low = mid +1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};