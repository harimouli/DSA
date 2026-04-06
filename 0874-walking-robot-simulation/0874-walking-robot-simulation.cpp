class Solution {
public:

    long long   getEcValue(int x, int y){

        return 1LL * x * x + 1LL * y * y;

    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        



            int n = commands.size();
            map<pair<int, int>, int> mpp;

            for(auto ob : obstacles) {
                mpp[{ob[0], ob[1]}]++;
            }

            char direction = 'N';
            int x = 0;
            int y = 0;
        long long ans = 0;
            for(int i = 0; i<n; i++){
                int cmd = commands[i];

                if(direction == 'N'){

                    if(cmd >= 1){
                        
                        while(cmd > 0){
                            if(mpp[{x, y + 1}]) break;
                            y++;
                            cmd--;
                             ans = max(ans, getEcValue(x, y));
                        }
                    }else if(cmd == -1){
                            direction = 'E';
                    }else{
                        direction = 'W';
                    }
                }

                // direction east 
                else if(direction == 'E'){

                    if(cmd >= 1){

                        while(cmd > 0){
                            if(mpp[{x + 1, y}]) break;
                            x++;
                            cmd--;
                            ans = max(ans, getEcValue(x, y));
                        }
                      
                    }else if(cmd == -1){
                        direction = 'S';
                    }else{
                        direction = 'N';
                    }
                }

                // direction west 

                else if(direction == 'S'){


                    if(cmd >= 1){

                        while(cmd > 0){
                            if(mpp[{x, y - 1}]) break;
                            y--;
                            cmd--;
                            ans = max(ans, getEcValue(x, y));
                        }
                    }
                    else if(cmd == -1){
                        direction = 'W';
                    }else {
                        direction = 'E';
                    }
                }
                
                else if(direction == 'W'){


                    if(cmd >= 1){
                        while(cmd > 0){
                            if(mpp[{x- 1, y}]) break;
                            cmd--;
                            x--;
                            ans = max(ans, getEcValue(x, y));
                        }
                    }else if(cmd == -1){
                        direction = 'N';
                    }else{
                        direction = 'S';
                    }
                }
            }
            return ans;
    }
};