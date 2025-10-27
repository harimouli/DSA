class Solution {
public:

    void getCom(int num, int k, int n, vector<int>&temp, vector<vector<int>>&res){

        if(n == 0 && temp.size() == k) {
            res.push_back(temp);
            return;
        }

        if(n < 0 || temp.size() == k || num > 9) return;


        temp.push_back(num);
        getCom(num + 1, k, n - num, temp, res);
        temp.pop_back();
        getCom(num + 1, k, n, temp, res);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>temp;
        vector<vector<int>>res;

        getCom(1, k, n, temp, res);
        return res;





    }
};