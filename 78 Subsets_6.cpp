// 78
// Subsets
// https://leetcode.com//problems/subsets/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> x;
        subsets(S,0,x);
        return output;
    }
    void subsets(vector<int> &S, int t, vector<int> &x)
    {
        if(t>=S.size())
            output.push_back(x);
        else
        {
            subsets(S,t+1,x);
            x.push_back(S[t]);
            subsets(S,t+1,x);
            x.pop_back();
        }
    }
    vector<vector<int>> output;
};