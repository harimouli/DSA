class Solution {
  public:
    int minValue(string &s, int k) {
        vector<int> hash(26, 0);
        
        
        for(int i = 0; i<s.size(); i++){
            hash[s[i] - 'a']++;
        }
        
        priority_queue<int>pq;
        
        for(int i = 0; i<26; i++){
            if(hash[i] != 0) pq.push(hash[i]);
        }
        int count = 0;
        while(!pq.empty() && count < k){
            int maxFreq = pq.top();
            pq.pop();
            maxFreq--;
            pq.push(maxFreq);
            count++;
        }
        int value = 0;
        while(!pq.empty()){
            value += pq.top() * pq.top();
            pq.pop();
        }
        return value;
        
        
    }
};