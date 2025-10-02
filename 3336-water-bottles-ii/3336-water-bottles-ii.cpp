class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int value = 0;
        int empty = numBottles;
        while(empty >= numExchange){
            int ans = 0;
            while(empty >= numExchange) {
                 empty -= numExchange;
                 numExchange++;
                 ans++;
                 
            }
            value += ans;
            empty  += ans;
            ans = 0;
            
        }
        return numBottles + value;
    }
};