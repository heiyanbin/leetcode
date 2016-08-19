// 139
// Word Break
// https://leetcode.com//problems/word-break/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.size() + 1, false);
        f[0] = true;
        
        size_t maxLen = 0;
        for (auto &word : dict)
            maxLen = max(maxLen, word.size());
        
        for (int i = 1; i <= s.size(); i++)
            for (int j = i - 1; j >= 0 && i - j <= maxLen; j--)
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    f[i]=true;
                    break;
                }
                
        return f[s.size()];        
    }
    
};