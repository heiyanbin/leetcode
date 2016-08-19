// 140
// Word Break II
// https://leetcode.com//problems/word-break-ii/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> d(s.size()+1);
        unordered_map<string,vector<string>> c;
        d[s.size()]=true;
        c[""]=vector<string>{""};
        for(int i=s.size()-1;i>=0;--i)
            for(int j=i;j<s.size();++j) {
                auto sub = s.substr(i,j-i+1);
                if(d[j+1] && dict.find(sub)!=dict.end())
                {
                    d[i]=true;
                    auto cur = s.substr(i);
                    for(auto &e : c[s.substr(j+1)])
                        c[cur].push_back(e.empty()? sub : sub + " " + e);
                }
            }
        return c[s];
    }
};