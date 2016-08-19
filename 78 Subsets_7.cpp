// 78
// Subsets
// https://leetcode.com//problems/subsets/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        output.push_back(vector<int>());
        sort(S.begin(), S.end());
        vector<int> x(S.size());
        subsets(S,0,x,0);
        return output;
    }
    void subsets(vector<int> &S, int t, vector<int> x, int start)
    {
        for(int i=start;i<S.size();i++)
        {
            x[t]=S[i];
            output.push_back(vector<int>(x.begin(),x.begin()+t+1));
            subsets(S,t+1,x,i+1);
        }
    }
    vector<vector<int>> output;
};