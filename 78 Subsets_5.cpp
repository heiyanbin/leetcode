// 78
// Subsets
// https://leetcode.com//problems/subsets/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> x(S.size());
        subsets(S,0,x,0);
        return output;
    }
    void subsets(vector<int> &S, int t, vector<int> &x, int index)
    {
        if(t>=S.size())
            output.push_back(vector<int>(x.begin(),x.begin()+index));
        else
        {
            subsets(S,t+1,x,index);
            x[index]=S[t];
            subsets(S,t+1,x,index+1);
        }
    }
    vector<vector<int>> output;
};