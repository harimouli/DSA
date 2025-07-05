class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for(int i = 0; i<arr.size(); i++){
            mpp[arr[i]]++;
        }

        int ans = -1;

        for(auto &pair : mpp){
            if(pair.second == pair.first) {
                if(pair.first > ans){
                    ans = pair.first;
                }
            }
        }
        return ans;
    }
};