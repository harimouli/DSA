class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        

        vector<int> outD(n+1, 0);
        vector<int> inD(n+1, 0);

        for(auto edge : trust){
            int a  = edge[0];
            int b = edge[1];

            outD[a]++;
            inD[b]++;
        }


        for(int i = 1; i<n+1; i++){
            if(outD[i] == 0 && inD[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};