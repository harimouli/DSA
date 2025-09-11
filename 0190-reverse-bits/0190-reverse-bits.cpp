class Solution {
public:
    int reverseBits(int n) {
        
    
            string bin = "";


            for(int i = 0; i<=31; i++) {
                if(n % 2) bin += '1';
                else bin += '0';
                n /= 2;
            }

            cout<<bin;
            int  size = bin.size();
            int ans = 0;
            int pow = 0;
            while(size) {
                if(bin[size-1] == '1') ans += (1  << pow); 
                pow++;
                size--;
            }
            return ans;

    }
};