class Solution {
public:
    int countCollisions(string directions) {
        


        stack<char>stk;

        int collisions = 0;
        for(char car : directions){

            if(!stk.empty() && stk.top() == 'R' && car == 'L'){
                collisions += 2;
                stk.pop();
                stk.push('S');
            }
            else if(!stk.empty() && stk.top() == 'R' && car == 'S'){
                collisions +=1;
                stk.pop();
                stk.push('S');
            }
            else if(!stk.empty() && stk.top() == 'S' && car == 'L'){
                collisions += 1;
            }
            else {
                stk.push(car);
            }
        }
        
        while(!stk.empty() && stk.top() =='R'){
            stk.pop();
        }

        while(!stk.empty()){
            if(stk.top() == 'R') collisions++;
            stk.pop();
        }

        return collisions;
    }
};