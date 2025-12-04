class Solution {
public:


    

    bool check(int left, int right, string s){

        if(left == right) return true;

        while(left <= right) {
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }


    void makePartition(int indx, string s, vector<vector<string>> &res, vector<string> &temp){

            int n = s.size();

            if(indx == n){
                res.push_back(temp);
                return;
            }


            for(int j = indx; j<n; j++){
                if(check(indx, j, s)){
                    temp.push_back(s.substr(indx, j - indx + 1));

                    makePartition(j + 1, s, res, temp);
                    temp.pop_back();
                }
            }
    }
    vector<vector<string>> partition(string s) {


            vector<vector<string>> res;
            vector<string>temp;


            makePartition(0, s, res, temp);

            return res;

    }
};