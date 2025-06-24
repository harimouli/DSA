class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int sumFive = 0;
        int sumTen = 0;

        int n = bills.size();
        for(int i = 0; i<n; i++){
            if(bills[i] == 5) sumFive += 5;
            else if(bills[i] == 10) {
                if(sumFive < 5) return false;
                else sumFive -= 5;
                sumTen += 10;
            }
            else{
                if(sumFive < 5) return false;
                else if(sumTen < 10 && sumFive < 15) return false;
                else if(sumTen < 10 && sumFive >= 15){
                    sumFive -= 15;
                }
                else{
                    sumFive -= 5;
                    sumTen -= 10;
                }
                 
            }
        }

        return true;
    }
};