// 140
// Word Break II
// https://leetcode.com//problems/word-break-ii/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return DFS(s,dict);
    }
    vector<string> DFS(string s, unordered_set<string> &dict)
    {
        if(s.empty()) return vector<string>(1,"");
        else
        {
            if(cache.find(s)!=cache.end()) return cache[s];
            vector<string> ret;
            for(int i=1;i<=s.length();++i)
            {
                auto sub = s.substr(0,i);
                if(dict.find(sub)!=dict.end())
                {
                    for(auto t : DFS(s.substr(i,s.length()-i),dict))
                        ret.push_back(sub + (t.empty() ? "": " "+ t));
                }
            }
            return cache[s]=ret;
        }
    }
private:
    unordered_map<string,vector<string>> cache;
};