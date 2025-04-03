class Solution {
public:
    bool isValid(string s) {
        stack<char> st;


        for(auto x : s){
            if(x == '[' || x == '{' || x == '('){
                st.push(x);
            }
            else{

                if(st.empty()){
                    return false;
                }
                else{
                    char cur = st.top();
                    st.pop();
                    if((cur == '(' && x == ')') || (cur == '[' && x == ']') || (cur == '{' && x == '}')){                        continue;
                    }
                    else{
                        return false;
                    }

                }
            }
        }
        if(st.empty()) return true;
        return false;

    }
};