class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long key = num / 3;
        if(key + key-1+ key+1 == num){
            return {key-1, key, key+1};
        }
        return {};
    }
};