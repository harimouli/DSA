#define ll long long int
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        
       
        vector<ll> freeTime(n, 0);
        ll ansTime = 0;  
        for (int i = 0; i < n; ++i) {
            
            ansTime += skill[i] * mana[0];
            freeTime[i] = ansTime;  
        }

        
        for (int j = 1; j < m; ++j) {
           
            ll tempTime = freeTime[0] + (1ll * skill[0] * mana[j]);
            freeTime[0] = tempTime;
            
            
            for (int i = 1; i < n; ++i) {
                
                tempTime = max(tempTime, freeTime[i]) + (1ll * skill[i] * mana[j]);
                freeTime[i] = tempTime;
            }

            
            for (int i = n - 2; i >= 0; --i) {
               
                ll nextWizardStartTime = freeTime[i + 1] - (1ll * skill[i + 1] * mana[j]);
                freeTime[i] = max(nextWizardStartTime, freeTime[i]);
            }
            
            
            ansTime = max(ansTime, freeTime[n - 1]);
        }

        return ansTime;
    }
};