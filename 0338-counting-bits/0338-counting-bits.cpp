class Solution {
public:
    int getBitsCount(int n){

        int count = 0;

        while(n != 0){
            count++;
            n = n & (n-1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        
        vector<int> ans;
        for(int i = 0; i<=n; i++){
            int bitCount = getBitsCount(i);
            ans.push_back(bitCount); 
        }
        return ans;
        
    }
};