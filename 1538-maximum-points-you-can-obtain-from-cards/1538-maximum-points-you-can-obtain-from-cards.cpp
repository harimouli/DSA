class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxSum = 0;
        int leftSum = 0;

        for(int i = 0; i<k; i++){
            leftSum += cardPoints[i];
        }

        maxSum = leftSum;

        int rightIndex = n - 1;
        for(int i = k-1; i>=0; i--){
            leftSum -= cardPoints[i];
            leftSum += cardPoints[rightIndex];

            if(leftSum > maxSum) {
                maxSum = leftSum;
            }
            rightIndex--;
            
        }
        return maxSum;
    }
};