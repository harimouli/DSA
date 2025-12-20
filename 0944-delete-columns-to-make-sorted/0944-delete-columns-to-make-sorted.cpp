class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        


        int m = strs.size();
        int n = strs[0].size();
        int res = 0;
        for(int col = 0; col < n; col ++){
            for(int i = 0; i<m-1; i++){
                    if(strs[i][col] > strs[i+1][col]) {
                            res++;
                            break;
                    }
            }
        }
        return res;
    }
};