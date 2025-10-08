class Solution {
public:

    int getValue(int spell, vector<int> &potions, long long success) {
        
        int low = 0;
        int n = potions.size();
        int high = potions.size() - 1;

        int index = -1; 
        while(low <= high) {
                int mid = (low + high) /2;
                long long val = (long long)potions[mid] * (long long )spell;
                if(val >= success) {
                    high = mid-1;
                    index = mid;
                }
                else {
                    low = mid + 1;

                }
        }
        if(index == -1) return 0;
        return n - index;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(), potions.end());
        vector<int>ans;
        for(int i = 0; i<spells.size(); i++) {
            ans.push_back(getValue(spells[i], potions, success));
        }
        return ans;
    }
};