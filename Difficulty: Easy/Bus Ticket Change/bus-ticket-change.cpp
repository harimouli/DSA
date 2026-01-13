class Solution {
  public:
    bool canServe(vector<int> &arr) {
        
        int n = arr.size();
        int tens  = 0;
        int fives = 0;
      
        for(int i = 0; i<n; i++){
            int change = arr[i] - 5;
            if(arr[i] == 20){
                if(tens <= 0 && fives <=0) return false;
                else {
                    if(tens > 0 && fives > 0) {
                        tens--;
                        fives--;
                    }else{
                        if(fives < 3) return false;
                        else fives -= 3;
                    }
                }
            }
            else if(arr[i] == 10){
                if(fives == 0) return false;
                else fives--;
                tens++;
            }else{
                fives++;
            }
        }
        return true;
    }
};