// 90
// Subsets II
// https://leetcode.com//problems/subsets-ii/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> d(1,vector<int>());
        for(int i=1,last_sz=0;i<=S.size();++i)
        {
            int  sz = d.size();
            for(int j= i>1 && S[i-2]==S[i-1] ? last_sz:0; j<sz; ++j) {
                auto v = d[j];
                v.push_back(S[i-1]);
                d.push_back(v);
            }
            last_sz = sz;
        }
        return d;
    }
};