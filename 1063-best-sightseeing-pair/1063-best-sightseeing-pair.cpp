class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int leftValue = values[0] ;
        int maxScore = INT_MIN;
        for(int i = 1; i<values.size(); i++){
            int rightValue = values[i] - i;
            maxScore = max(leftValue+ rightValue, maxScore);
            int x = values[i] + i;
            leftValue = max(leftValue, x);
        }
        return maxScore;
    }
};