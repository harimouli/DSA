class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = height[0];
        suffix[n-1] = height[n-1];

        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
        for(int j = n-2; j >= 0; j--){
            suffix[j] = max(suffix[j+1], height[j]);
        }
        int water = 0;
        for(int i =0; i<n; i++){
            water += min(prefix[i], suffix[i]) - height[i];
        }
        return water;


    }
};