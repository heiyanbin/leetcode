// 131
// Palindrome Partitioning
// https://leetcode.com//problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> par(s.size(),vector<bool>(s.size()));
        vector<vector<vector<string>>> c(s.size());
        for(int i=s.size()-1;i>=0;--i)
            for(int j=i;j<s.size();++j)
                if(s[i]==s[j] && (j-i<2 || par[i+1][j-1]))
                {
                    par[i][j]=true;
                    const string p= s.substr(i,j-i+1);
                    if(j+1<s.size())
                        for(auto v : c[j+1])
                        {
                            v.insert(v.begin(),p);
                            c[i].push_back(v);
                        }
                    else
                        c[i].push_back(vector<string>{p});
                }
        return c[0];
    }
};