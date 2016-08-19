// 90
// Subsets II
// https://leetcode.com//problems/subsets-ii/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> x(S.size());
        v.push_back(vector<int>());
        sort(S.begin(),S.end());
        select(S,0,x,0);
        return v;
    }
    void select(vector<int> &S, int t, vector<int> &x, int start)
    {
        for(int i=start;i<S.size();i++)
        {
            if(i!= start && S[i]==S[i-1]) continue;
            x[t] = S[i];
            v.push_back(vector<int>(x.begin(),x.begin()+t+1));
            select(S,t+1,x,i+1);
        }
    }
    
private:
    vector<vector<int>> v;
};