class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles ; 
        int empty = numBottles ; 
        while(empty >= numExchange){
            int x = empty / numExchange ; 
            ans += x ; 
            empty = empty % numExchange ; 
            empty += x ; 
        }
        return ans ; 
    }
};