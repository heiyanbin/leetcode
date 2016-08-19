// 78
// Subsets
// https://leetcode.com//problems/subsets/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> x;
        subsets(S,0,x,0);
        return output;
    }
    void subsets(vector<int> &S, int t, vector<int> x, int start)
    {
        output.push_back(x);
        for(int i=start;i<S.size();i++)
        {
            x.push_back(S[i]);
            subsets(S,t+1,x,i+1);
            x.pop_back();
        }
    }
    vector<vector<int>> output;
};