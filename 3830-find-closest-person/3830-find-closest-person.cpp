class Solution {
public:
    int findClosest(int x, int y, int z) {
        int s1 = abs(x - z);
        int s2 = abs(y - z);
        
        if(s1 == s2) return 0;
        if(s1 > s2) return 2;
        return 1;
    }
};