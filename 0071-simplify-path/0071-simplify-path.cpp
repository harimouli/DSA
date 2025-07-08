class Solution {
public:
    string simplifyPath(string path) {
        

      string orgPath ="";
      stringstream ss(path);
      vector<string> p;
      while(getline(ss, orgPath, '/')){
          if(orgPath == ".."){
            if(p.size() > 0) {
                p.pop_back();
            }
          }else if(orgPath != "" && orgPath != "."){
            p.push_back(orgPath);
          }
          
      }
      if(p.size() == 0) return "/";
     string ans = "";
      for(int i = 0; i<p.size(); i++){
        if(p[i] != "" && p[i] != ".") ans += '/' + p[i];
      }
        return ans;
    }
};