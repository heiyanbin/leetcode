// 39
// Combination Sum
// https://leetcode.com//problems/combination-sum/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> x;
        backtrack(0,x,candidates,target);
        vector<vector<int> > output(outSet.begin(),outSet.end());
        return output;
    }
    
    void backtrack(int t, vector<int> &x, vector<int> &candidates, int target)
    {
        for(int i=0;i<candidates.size();i++)
        {
            if(x.size()<=t)
                x.push_back(candidates[i]);
            else
                x[t] = candidates[i];
            if(x[t]==target)
            {
                vector<int> v(x.begin(),x.begin()+t+1);
                sort(v.begin(),v.end());
                outSet.insert(v);
            }
            else if(x[t]<target)
                backtrack(t+1, x, candidates, target-x[t]);
        }
    }
private:
    set<vector<int>> outSet;
};