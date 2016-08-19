// 78
// Subsets
// https://leetcode.com//problems/subsets/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> d(1,vector<int>());
        for(int i=1;i<=S.size();++i)
            for(int j=0,end=d.size();j<end;++j) {
                auto v = d[j];
                v.push_back(S[i-1]);
                d.push_back(v);
            }
        return d;
    }
};