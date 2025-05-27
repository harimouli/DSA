class Solution {
public:
    int totalFruit(vector<int>& fruits) {
          unordered_map<int, int> mp;
        int i  = 0;
        int j = 0;
        int n = fruits.size();
        int maxLen = 0;
        while(j < n){
            mp[fruits[j]]++;
            if(mp.size() > 2){
                    while(mp.size() > 2){
                        mp[fruits[i]]--;
                        if(mp[fruits[i]] == 0){
                            mp.erase(fruits[i]);
                        } 
                        i++;
                    }
            }
            if(mp.size() <= 2){
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
        return maxLen;
    }
};