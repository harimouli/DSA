class Solution {
    string addA(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }
        return s;
    }

    string rotateB(string s, int b) {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);
        string ans = s;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            ans = min(ans, curr);

            // Operation 1: Add 'a' to digits at odd indices
            string s1 = addA(curr, a);
            if (!vis.count(s1)) {
                vis.insert(s1);
                q.push(s1);
            }

            // Operation 2: Rotate string by 'b' positions
            string s2 = rotateB(curr, b);
            if (!vis.count(s2)) {
                vis.insert(s2);
                q.push(s2);
            }
        }

        return ans;
    }
};