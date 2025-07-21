class Solution {
public:
    string makeFancyString(string s) {
        
        vector<char> chars(s.begin(), s.end());


        int n = s.size();
        int pos = 1;
        char last = chars[0];
        int count = 1;
        for(int i = 1; i<chars.size(); i++){

            if(chars[i] != last){
                count = 0;
                last = chars[i];
            }

            if(++count > 2) continue;

            chars[pos++] = chars[i];
        }
        return string(chars.begin(), chars.begin()+pos);
    }
};