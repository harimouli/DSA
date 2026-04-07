class Solution {
public:

    long long   getEcValue(int x, int y){

        return 1LL * x * x + 1LL * y * y;

    }


    void  move(int &x, int &y, int cmd, int&direction,  map<pair<int, int>, int>& mpp, long long& ans){
        vector<vector<int>> directions = {{0, 1},{1, 0}, {-1, 0}, {0, -1}};

            
            while(cmd > 0){
                if(mpp[{x + directions[direction][0], y + directions[direction][1]}]) break;

                x += directions[direction][0];
                y += directions[direction][1];
                cmd--;
                ans = max(ans, getEcValue(x, y));
            }
         

    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        



            int n = commands.size();
            map<pair<int, int>, int> mpp;

            for(auto ob : obstacles) {
                mpp[{ob[0], ob[1]}]++;
            }

            int direction = 0;
            int x = 0;
            int y = 0;
        long long ans = 0;
            for(int i = 0; i<n; i++){
                int cmd = commands[i];

                if(direction ==  0){

                    if(cmd >= 1){
                        move(x, y, cmd, direction, mpp, ans);
                       
                    }else if(cmd == -1){
                            direction = 1;
                    }else{
                        direction = 2;
                    }
                }

                // direction east 
                else if(direction == 1){

                    if(cmd >= 1){

                        move(x, y, cmd, direction, mpp, ans);
                      
                    }else if(cmd == -1){
                        direction = 3;
                    }else{
                        direction = 0;
                    }
                }

                // direction west 

                else if(direction == 3){


                    if(cmd >= 1){

                        move(x, y, cmd, direction, mpp, ans);
                    }
                    else if(cmd == -1){
                        direction = 2;
                    }else {
                        direction = 1;
                    }
                }
                
                else if(direction == 2){


                    if(cmd >= 1){
                         move(x, y, cmd, direction, mpp, ans);
                    }else if(cmd == -1){
                        direction = 0;
                    }else{
                        direction = 3;
                    }
                }
            }
            return ans;
    }
};