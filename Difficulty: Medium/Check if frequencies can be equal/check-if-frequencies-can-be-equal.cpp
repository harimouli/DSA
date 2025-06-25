class Solution {
  public:
  
  
    bool checkSame(vector<int> hash){
        int target = 0;
        int count = 0;
        for(int i = 0; i<26; i++){
           if(hash[i] != 0){
               if(count == 0) target = hash[i];
               else if(target != hash[i]) return false;
               count++;
           }
        }
        return true;
    }
    bool sameFreq(string& s) {
        vector<int>hash(26, 0);
        
        int n = s.size();
        for(int i = 0; i<n; i++){
            hash[s[i] - 'a']++;
        }
        
         if(checkSame(hash)) return true;
        
        
        for(int i = 0; i<26; i++){
            if(hash[i] != 0)  {
                
                hash[i]--;
                if(checkSame(hash)) return true;
                hash[i]++;
            }
            
          
        }
        return false;
        
        
        
    }
};