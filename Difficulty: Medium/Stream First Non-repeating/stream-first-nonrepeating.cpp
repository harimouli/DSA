class Solution {
  public:
    string firstNonRepeating(string &s) {
        
        
        int n = s.size();
        queue<char>pq;
        
        unordered_map<int,int>right;
        string ans = "";
        for(int i = 0; i<n; i++){
            right[s[i]]++;
            pq.push(s[i]);
            
            while(!pq.empty() && right[pq.front()] > 1 ){
                pq.pop();
            }
            
            if(pq.empty()) {
                ans += '#';
            }
            else{
                ans += pq.front();
            }
        }
       
        return ans;
        
        
    }
};