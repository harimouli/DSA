class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {


         vector<int> sorted_arr = arr;

         sort(sorted_arr.begin(), sorted_arr.end());


         unordered_map<int, int> rank;


         int currentRank = 1;

         for(int num : sorted_arr){
                if(!rank.count(num)){
                    rank[num] = currentRank++;
                }
         }

         for(int &num : arr){
            num = rank[num];
         }
    return arr;

    }
};