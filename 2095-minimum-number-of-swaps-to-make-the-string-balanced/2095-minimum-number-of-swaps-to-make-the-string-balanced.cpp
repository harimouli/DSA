class Solution {
public:
    int minSwaps(string s) {
        
        int n = s.size();

        int open = 0;
        int close = 0;


        for(int i = 0; i<n; i++){
            if(s[i] == '['){
                open++;
            }else{
                if(open > 0) open--;
                else close++;
            }
        }

        int swap = min(open, close);

        return (swap + 1) / 2;




    }
};