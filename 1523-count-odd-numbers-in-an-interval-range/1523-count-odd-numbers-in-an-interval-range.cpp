class Solution {
public:
    int countOdds(int low, int high) {
        

        int res = 0;
        for(int  left = low; left<=high; left++){
            if(left % 2) res++;
        }
        return res;
    }
};