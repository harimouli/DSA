class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int matchs = 0;
        int m = players.size();
        int n = trainers.size();

        int i = 0; 
        int j = 0;
        while(i < m &&  j < n){
            if(players[i] <= trainers[j]){
                matchs++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return matchs;
    }
};