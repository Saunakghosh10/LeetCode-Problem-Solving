class Solution {
private:
    bool checkSame(string &s, string &t) {
        int sz = size(s);
        int diff = 0;
        for(int i = 0; i < sz; ++i) {
            if(s[i] != t[i]) {
                ++diff;
            }
            if(diff > 2)
                return false;
        }
        
        return (diff <= 2);
    }
    
    void dfs(vector<string> &strs, string &check) {
        for(int i = 0; i < strs.size(); ++i) {
            if(strs[i] == "")
                continue;
            
            if(checkSame(strs[i], check)) {
                string temp = strs[i];
                strs[i] = "";
                dfs(strs, temp);
            }
            
        }
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(strs[i] == "")
                continue;
            
            string temp = strs[i];
            strs[i] = "";
            
            cnt++;
            dfs(strs, temp);
        }
        
        return cnt;
    }
};
