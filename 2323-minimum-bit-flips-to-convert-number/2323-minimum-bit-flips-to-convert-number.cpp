class Solution {
public:
    int minBitFlips(int start, int goal) {
        int value = start ^ goal;
        int count = 0;
        while(value != 0){
             count++;
            value = value & (value - 1);
        }
        return count;
    }
};