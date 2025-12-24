class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int totalApples = 0;

        for(int app : apple){
            totalApples += app ;
        }

        sort(capacity.begin(), capacity.end());
            int n = capacity.size();
            int ind = n - 1;
            int ans = 0;
            while(ind >= 0 && totalApples > 0){
                totalApples -= capacity[ind];
                ans++;
                ind--;
            }
            return ans;
    }
};