class Solution {
public:
    bool check(int num) { 

        while(num != 0) {
            if(num %10 == 0) return false;
            num = num / 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i = 1; i<n; i++){
            int x1 = i;
            int x2 = n - i;
            if(check(x1) && check(x2))  return {x1, x2};
        }
        return {-1, -1};
       
    }
};