// 140
// Word Break II
// https://leetcode.com//problems/word-break-ii/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> d(s.size()+1);
        vector<vector<int>> prev(s.size()+1);
        d[0]=true;
        for(int i=1;i<=s.size();++i)
            for(int j=i-1;j>=0;--j) {
                if(d[j] && dict.find(s.substr(j,i-j))!=dict.end())
                {
                    d[i] = true;
                    prev[i].push_back(j);
                }
            }
        vector<string> res;
        get_path(s,prev,s.size(),"",res);
        return res;
        
    }
    void get_path(string &s, vector<vector<int>> &prev, int i, string path, vector<string> &res) {
        if(i==0) res.push_back(path);
        else
            for(auto j: prev[i])
                get_path(s, prev, j, path.empty()? s.substr(j,i-j): s.substr(j,i-j)+" "+path, res);
    }
};