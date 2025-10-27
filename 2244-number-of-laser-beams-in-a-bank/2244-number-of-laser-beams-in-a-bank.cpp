class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        

        int m = bank.size();
        int n = bank[0].size();
        vector<int>devices;
        for(int i = 0; i<m; i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(bank[i][j] == '1') {
                        cnt++;
                }
            }
          
           if(cnt) devices.push_back(cnt);
        }

      
        int ans = 0;
       for(int  i =1; i<devices.size(); i++){
            ans = ans + devices[i-1] * devices[i];
       }
       return ans;
    }
};