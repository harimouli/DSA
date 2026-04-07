class Robot {
public:
    int h;
    int w;
    int x;
    int y;
    int direction;
    Robot(int width, int height) {
        h = height;
        w = width;
        x = 0;
        y = 0;
        direction = 0;
    }
    
    void step(int num) {
        
        int perimeter = 2 * (w + h) - 4;
        num %= perimeter;
            if(num == 0 && x == 0 && y == 0) {
            direction = 3; // South
            return;
        }
        while(num > 0){
            
            if(direction == 0){ // east;
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if(move == 0) direction = 1;
            }
            else if(direction == 1){ // north

                int move = min(num,     h- 1- y);
                y += move;
                num -= move;
               if(move == 0) direction = 2;
            }else if(direction == 2){
                int move = min(num, x);
                x -= move;
                num -= move;
                if(move == 0) direction = 3;
            }else{
                
                int move = min(num, y);
                y -= move;
                num -= move;
                if(move == 0) direction = 0;
            }

        }


    }
    
    vector<int> getPos() {
        return {x, y};
        
    }
    
    string getDir() {
        if(direction == 0) return "East";
        if(direction == 1) return "North";
        if(direction == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */