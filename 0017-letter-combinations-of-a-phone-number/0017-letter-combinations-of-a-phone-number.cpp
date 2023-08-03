class Solution {
private:
    
    /*
        Time Complexity : O(4^n)
        Space Complexity : O(n)
    */
    
    vector<string> res;
    string temp;
    unordered_map<char, string> m1;
    
    void helper(int idx, string digits){
        if(idx>=digits.size()){
            res.push_back(temp);
            return;
        }
        
        for(char ch : m1[digits[idx]]){
            temp.push_back(ch);
            helper(idx+1, digits);
            temp.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        
        m1['2'] = "abc";
        m1['3'] = "def";
        m1['4'] = "ghi";
        m1['5'] = "jkl";
        m1['6'] = "mno";
        m1['7'] = "pqrs";
        m1['8'] = "tuv";
        m1['9'] = "wxyz";
        
        helper(0, digits);
        
        return res;
    }
};