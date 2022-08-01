class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> m;
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        
        unordered_set<int> s;
        
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(s.find(it->second) != s.end())
                return false;
            
            s.insert(it->second);
        }
        
        return true;
        
    }
};