class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
       
       
       int n = cardPoints.size();
       
       int left = 0;
       
       
       int maxScore = 0;
       
       
       while(left  < k){
           maxScore += cardPoints[left];
           left++;
       }
       
       if(left > 0) left--;
       
       int score = maxScore;
       int right = n - 1;
       
       while(left >= 0){
           score -= cardPoints[left];
           score += cardPoints[right];
           maxScore = max(score, maxScore);
           left--;
           right--;
       }
       
       return maxScore;
       
    }
};
